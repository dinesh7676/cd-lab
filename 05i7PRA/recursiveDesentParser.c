#include &lt;stdio.h&gt;
#include &lt;string.h&gt;
int main() {
char input[100], stack[100];
int pos = 0, top = -1;
printf(&quot;Enter input string (e.g., i or i+i): &quot;);
scanf(&quot;%99s&quot;, input);
int len = strlen(input);
input[len] = &#39;$&#39;;
input[len + 1] = &#39;\0&#39;;
stack[++top] = &#39;$&#39;;
stack[++top] = &#39;E&#39;;
printf(&quot;\n%-20s | %-20s\n&quot;, &quot;Stack&quot;, &quot;Input Lookahead&quot;);
printf(&quot;-----------------------------------------\n&quot;);
while (top &gt;= 0) {
stack[top + 1] = &#39;\0&#39;;
printf(&quot;%-20s | %-20s\n&quot;, stack, &amp;input[pos]);
char stack_top = stack[top--];
char token = input[pos];
if (stack_top == token) {
if (stack_top != &#39;$&#39;) pos++;
}
else if (stack_top == &#39;E&#39; &amp;&amp; token == &#39;i&#39;) {
stack[++top] = &#39;X&#39;; // Expand E -&gt; T X
stack[++top] = &#39;T&#39;;
}
else if (stack_top == &#39;T&#39; &amp;&amp; token == &#39;i&#39;) {
stack[++top] = &#39;i&#39;; // Expand T -&gt; i
}
else if (stack_top == &#39;X&#39;) {
if (token == &#39;+&#39;) {
stack[++top] = &#39;E&#39;; // Expand X -&gt; + E
stack[++top] = &#39;+&#39;;

}
else if (token != &#39;$&#39;) {
printf(&quot;\nString Rejected (Invalid choice for X)\n&quot;);
return 0;
}
}
else {
printf(&quot;\nString Rejected (Syntax Error)\n&quot;);
return 0;
}
}
if (input[pos] == &#39;$&#39;)
printf(&quot;\nString Accepted\n&quot;);
else
printf(&quot;\nString Rejected (Unparsed extra tokens remaining)\n&quot;);
return 0;
}