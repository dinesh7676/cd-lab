#include &lt;stdio.h&gt;
#include &lt;string.h&gt;
int main() {
printf(&quot;Grammar:\nS -&gt; a\n\n&quot;);
char input[] = &quot;a&quot;;
char input_buf[10];
sprintf(input_buf, &quot;%s$&quot;, input);
char stack[20] = &quot;$&quot;;
int s_top = 0;
int state_stack[20] = {0};
int st_top = 0;
int ip = 0;
printf(&quot;Stack\t\tInput\t\tAction\n&quot;);
printf(&quot;-----------------------------------------\n&quot;);
while (1) {
int current_state = state_stack[st_top];
char tok = input_buf[ip];

if (current_state == 0) {
if (tok == &#39;a&#39;) {
s_top++;
stack[s_top] = &#39;a&#39;;
stack[s_top + 1] = &#39;\0&#39;;
printf(&quot;%s\t\t%s\t\tShift a\n&quot;, stack, input_buf + ip);
st_top++;
state_stack[st_top] = 2;
ip++;
} else {
printf(&quot;\nFailure: String Rejected.\n&quot;);
return 1;
}
}
else if (current_state == 2) {
if (tok == &#39;$&#39;) {

stack[s_top] = &#39;\0&#39;;
s_top--;
st_top--;
printf(&quot;%s\t\t%s\t\tReduce S -&gt; a\n&quot;, stack, input_buf + ip);

s_top++;
stack[s_top] = &#39;S&#39;;
stack[s_top + 1] = &#39;\0&#39;;
if (state_stack[st_top] == 0) {
st_top++;
state_stack[st_top] = 1;
}
} else {
printf(&quot;\nFailure: String Rejected.\n&quot;);
return 1;
}
}
else if (current_state == 1) {
if (tok == &#39;$&#39;) {
printf(&quot;%s\t\t%s\t\tAccept\n&quot;, stack, input_buf + ip);
printf(&quot;\nSuccess: String is Parsed / Accepted!\n&quot;);
break;
} else {
printf(&quot;\nFailure: String Rejected.\n&quot;);
return 1;
}
}
}
return 0;
}