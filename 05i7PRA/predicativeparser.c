#include &lt;stdio.h&gt;
char input[100];
int pos = 0;
int E();
int Eprime();
int T();
int T() {
if (input[pos] == &#39;i&#39;) {
pos++;
return 1;
}
return 0;
}
int Eprime() {
if (input[pos] == &#39;+&#39;) {
pos++;
if (T())
return Eprime();
return 0;
}
else if (input[pos] == &#39;*&#39;) {
pos++;
if (T())
return Eprime();
return 0;
}
return 1; // ε
}
int E() {
if (T())
return Eprime();
return 0;
}
int main() {
printf(&quot;Enter input (use i for id): &quot;);
scanf(&quot;%s&quot;, input);

if (E() &amp;&amp; input[pos] == &#39;\0&#39;)
printf(&quot;String Accepted\n&quot;);
else
printf(&quot;String Rejected\n&quot;);
return 0;
}