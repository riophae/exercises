#### 2.1

按增长率排列下列函数：N，![sqrt{N}](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Csmall%20%5Csqrt%7BN%7D)，![N^{1.5}](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Csmall%20N%5E%7B1.5%7D)，![N^{2}](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Csmall%20N%5E%7B2%7D)，![Nlog{N}](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Csmall%20Nlog%7BN%7D)，![Nlog{log{N}}](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Csmall%20Nlog%7Blog%7BN%7D%7D)，![Nlog^{2}{N}](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Csmall%20Nlog%5E%7B2%7D%7BN%7D)，![Nlog{(N^{2})}](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Csmall%20Nlog%7B%28N%5E%7B2%7D%29%7D)，![2/N](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Csmall%202/N)，![2^{N}](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Csmall%202%5E%7BN%7D)，![2^{N/2}](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Csmall%202%5E%7BN/2%7D)，![37](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Csmall%2037)，![N^{2}logN](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Csmall%20N%5E%7B2%7DlogN)，![N^{3}](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Csmall%20N%5E%7B3%7D)，指出哪些函数以相同的增长率增长。

**解答：**![2/N](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Csmall%202/N)，![37](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Csmall%2037)，![sqrt{N}](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Csmall%20%5Csqrt%7BN%7D)，N，![Nlog{log{N}}](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Csmall%20Nlog%7Blog%7BN%7D%7D)，![Nlog{N}](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Csmall%20Nlog%7BN%7D)，![Nlog{(N^{2})}](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Csmall%20Nlog%7B%28N%5E%7B2%7D%29%7D)，![Nlog^{2}{N}](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Csmall%20Nlog%5E%7B2%7D%7BN%7D)，![N^{1.5}](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Csmall%20N%5E%7B1.5%7D)，![N^{2}](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Csmall%20N%5E%7B2%7D)，![N^{3}](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Csmall%20N%5E%7B3%7D)，![2^{N/2}](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Csmall%202%5E%7BN/2%7D)，![2^{N}](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Csmall%202%5E%7BN%7D)，![N^{2}logN](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Csmall%20N%5E%7B2%7DlogN)。其中 ![Nlog{N}](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Csmall%20Nlog%7BN%7D) 和 ![Nlog{(N^{2})}](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Csmall%20Nlog%7B%28N%5E%7B2%7D%29%7D) 以相同的速率增长。

#### 2.2

设 ![T_{1}(N) = O(f(N))](https://latex.codecogs.com/gif.latex?T_%7B1%7D%28N%29%20%3D%20O%28f%28N%29%29) 和 ![T_{2}(N) = O(f(N))](https://latex.codecogs.com/gif.latex?T_%7B2%7D%28N%29%20%3D%20O%28f%28N%29%29)。下列哪些等式成立？

a. ![T_{1}(N) + T_{2}(N) = O(f(N))](https://latex.codecogs.com/gif.latex?T_%7B1%7D%28N%29%20&plus;%20T_%7B2%7D%28N%29%20%3D%20O%28f%28N%29%29) ✓  
b. ![T_{1}(N) - T_{2}(N) = o(f(N))](https://latex.codecogs.com/gif.latex?T_%7B1%7D%28N%29%20-%20T_%7B2%7D%28N%29%20%3D%20o%28f%28N%29%29) ×  
c. ![\frac{T_1(N)}{T_2(N)} = O(1)](https://latex.codecogs.com/gif.latex?%5Cfrac%7BT_1%28N%29%7D%7BT_2%28N%29%7D%20%3D%20O%281%29) ×  
d. ![T_1(N)=O(T_2(N))](https://latex.codecogs.com/gif.latex?T_1%28N%29%3DO%28T_2%28N%29%29) ×  

#### 2.10

考虑下述算法（称为 Horner 法则）。计算 ![F(X)=\sum_{i=0}^{N}A_iX^i](https://latex.codecogs.com/gif.latex?%5Cinline%20F%28X%29%3D%5Csum_%7Bi%3D0%7D%5E%7BN%7DA_iX%5Ei)的值：

```
Poly = 0
for (i = N; i >= 0; i--)
  Poly = X * Poly + A[i]
```

a. 对 ![X=3](https://latex.codecogs.com/gif.latex?%5Cinline%20X%3D3)，![F(X)=4X^4+8X^3+X+2](https://latex.codecogs.com/gif.latex?%5Cinline%20F%28X%29%3D4X%5E4&plus;8X%5E3&plus;X&plus;2) 指出该算法的各步是如何进行的。  
b. 解释该算法为什么能够解决这个问题。  
c. 该算法的运行时间是多少？

**解答：**  
a. 设 `A[N] = { 2, 1, 0, 8, 4 }` 并执行上面的程序即可求解。  
b. 将待求解式子中从常数项到最高项系数依次放入数组 `A[N]` 中（包括系数为 `0` 的项）。该算法会在迭代过程中反复乘以 `X`，次数越高的项乘 `X` 的次数越多，最终便能得到各项之和。  
c. ![O(N)](https://latex.codecogs.com/gif.latex?%5Cinline%20O%28N%29)

#### 2.11

给出一个有效的算法来确定在整数 ![A_1<A_2<A_3<...<A_N](https://latex.codecogs.com/gif.latex?%5Cinline%20A_1%3CA_2%3CA_3%3C...%3CA_N) 的数组中是否存在整数 ![i](https://latex.codecogs.com/gif.latex?%5Cinline%20i) 使得 ![A_i=i](https://latex.codecogs.com/gif.latex?%5Cinline%20A_i%3Di)。你的算法的运行时间是多少？

#### 2.12

给出有效的算法（及其运行时间分析）：  
a. 求最小子序列和。  
b. 求最小的正子序列和。  
c. 求最大子序列乘积。

**参考资料：**  
- http://stackoverflow.com/q/31640902/4617270
