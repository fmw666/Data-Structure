排列问题。设R={r<sub>1</sub>,r<sub>2</sub>,...,r<sub>n</sub>}是要进行排列的n个元素，R<sub>i</sub>=R-{r<sub>i</sub>}。集合X中元素的全排列记为 Perm(X)。(r<sub>i</sub>)Perm(X)表示在全排列 Perm(X)的每个排列前加上前缀r<sub>i</sub>得到的排列。R的全排列可归纳定义如下：

+ 当 n=1 时，Perm(R)=(r)，其中r是集合R中唯一的元素；

+ 当 n>1 时，Perm(R)由(r<sub>1</sub>)Perm(R<sub>1</sub>)，(r<sub>2</sub>)Perm(R<sub>2</sub>)，...，(r<sub>n</sub>)Perm(R<sub>n</sub>)构成。