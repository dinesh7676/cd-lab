#include &lt;stdio.h&gt;
#include &lt;string.h&gt;
int main() {
char stack[30],input[30],action[30];
int top = -1, i = 0, len;
printf(&quot;Grammar:\nE -&gt; E+E\nE -&gt; E*E\nE -&gt; id (enter &#39;i&#39; for id)\n\n&quot;);
printf(&quot;Enter input string: &quot;);
if (scanf(&quot;%29s&quot;, input) != 1) return 1;
len = strlen(input);
printf(&quot;\nStack\t\tInput\t\tAction\n&quot;);
printf(&quot;-----------------------------------------\n&quot;);
for (i = 0; i &lt; len; i++) {
top++;
stack[top] = input[i];
stack[top + 1] = &#39;\0&#39;;
printf(&quot;$%s\t\t%s$\t\tShift %c\n&quot;, stack, input + i + 1, input[i]);
if (stack[top] == &#39;i&#39;) {
stack[top] = &#39;E&#39;;
printf(&quot;$%s\t\t%s$\t\tReduce E -&gt; id\n&quot;, stack, input + i + 1);
}
if (top &gt;= 2 &amp;&amp; stack[top] == &#39;E&#39; &amp;&amp; stack[top - 2] == &#39;E&#39;) {
if (stack[top - 1] == &#39;+&#39;) {
top -= 2;
stack[top] = &#39;E&#39;;
stack[top + 1] = &#39;\0&#39;;
printf(&quot;$%s\t\t%s$\t\tReduce E -&gt; E+E\n&quot;, stack, input + i + 1);
} else if (stack[top - 1] == &#39;*&#39;) {
top -= 2;
stack[top] = &#39;E&#39;;
stack[top + 1] = &#39;\0&#39;;
printf(&quot;$%s\t\t%s$\t\tReduce E -&gt; E*E\n&quot;, stack, input + i + 1);

}
}
}
if (top == 0 &amp;&amp; stack[0] == &#39;E&#39;) {
printf(&quot;\nSuccess: String is Parsed / Accepted!\n&quot;);
} else {
printf(&quot;\nFailure: String Rejected.\n&quot;);
}
return 0;
}