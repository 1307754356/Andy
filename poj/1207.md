# C++ learn_note 2.4

标签（空格分隔）： C++ poj

---

#一个题目的陷阱 poj1207
>OUTPUT
>
For each pair of input integers i and j you should output i, j,and **the maximum cycle length for integers between and including i and j**. These three numbers should be separated by at least one space with all three numbers on one line and with one line of output for each line of input. The integers i and j must appear in the output in the same order in which they appeared in the input and should be followed by the maximum cycle length (on the same line).

注意，题目并没有说 i 和 j 的大小顺序，不能想当然地认为 i 小
```C++
       int x=i<j?i:j; //需要从i和j中较小的那个开始
       int y=i<j?j:i;
       for(int k=x;k<=y;++k)
       {
           maxn=(maxn>num(k))?maxn:num(k);
       }
```



