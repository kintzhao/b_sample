

[TOC]



 [贝塞尔曲线原理(简单阐述)](https://www.cnblogs.com/hnfxs/p/3148483.html)  <https://www.cnblogs.com/hnfxs/p/3148483.html>

参考: b-spline学习-系数计算及程序实践
https://blog.csdn.net/brightming/article/details/53953926

[AGG 之贝塞尔插值](https://www.iteye.com/blog/liyiwen-705489)https://www.iteye.com/blog/liyiwen-705489
[B-样条基函数：定义 （B-spline Basis Functions: Definition）](<https://blog.csdn.net/tuqu/article/details/5177405>)

[B-spline Curves 学习之前言 翻译](<https://www.cnblogs.com/icmzn/p/5100740.html>)

---------------------------------------------------------------

###  [贝塞尔曲线原理(简单阐述)](https://www.cnblogs.com/hnfxs/p/3148483.html) 

原理和简单推导（以三阶为例）：

设*P*0、*P*02、*P*2是一条抛物线上顺序三个不同的点。过*P*0和*P*2点的两切线交于*P*1点，在*P*02点的切线交*P*0*P*1和*P*2*P*1于*P*01和*P*11，则如下比例成立：

![img](https://images0.cnblogs.com/blog/500577/201306/21154457-2b055b21b1fe4426b118bc6382b481aa.jpg)

这是所谓抛物线的三切线定理。

 

![img](https://images0.cnblogs.com/blog/500577/201306/21154420-e9c48409b7d44b9baedc180352f6eb29.gif)

当*P*0，*P*2固定，引入参数*t*，令上述比值为*t*:(1-*t*)，即有：

![img](https://images0.cnblogs.com/blog/500577/201306/21154527-302a2599eb8f474f92a0d86c5b2a9e0c.jpg)
*t*从0变到1，第一、二式就分别表示控制二边形的第一、二条边，它们是两条一次Bezier曲线。将一、二式代入第三式得：

 ![img](https://images0.cnblogs.com/blog/500577/201306/21154747-9498ca0ff9d74c96b3b037aaa3b75875.gif)

当*t*从0变到1时，它表示了**由三顶点P0、P1、P2三点定义的一条二次Bezier曲线。**

并且表明：

这**二次Bezier曲线P02可以定义为分别由前两个顶点(P0,P1)和后两个顶点(P1,P2)决定的一次Bezier曲线的线性组合**。

依次类推，

由四个控制点定义的三次Bezier曲线*P*03可被定义为分别由(*P*0,*P*1,*P*2)和(*P*1,*P*2,*P*3)确定的二条二次Bezier曲线的线性组合，由(*n+*1)个控制点*P**i*(*i*=0,1,...,*n*)定义的*n*次Bezier曲线*P*0*n*可被定义为分别由前、后*n*个控制点定义的两条(*n*-1)次Bezier曲线*P*0*n-*1与*P*1*n-*1的线性组合：
![img](https://images0.cnblogs.com/blog/500577/201306/21154556-1bd9bc71310748c29bbb7f4150ccbb6d.gif)
由此得到Bezier曲线的递推计算公式

![img](https://images0.cnblogs.com/blog/500577/201306/21154633-cf5e1027b7e54703b87cf6155a205a46.gif)

这就是这就是de Casteljau算法，可以简单阐述三阶贝塞尔曲线原理。

 

下面是总结：转自<http://blog.csdn.net/tianhai110/article/details/2203572>

Bézier curve(贝塞尔曲线)是应用于二维图形应用程序的[数学曲线](http://baike.baidu.com/view/627248.htm)。 曲线定义：起始点、终止点（也称锚点）、控制点。通过调整控制点，贝塞尔曲线的形状会发生变化。 1962年，法国数学家Pierre Bézier第一个研究了这种[矢量](http://baike.baidu.com/view/77474.htm)绘制曲线的方法，并给出了详细的计算公式，因此按照这样的公式绘制出来的曲线就用他的姓氏来命名，称为贝塞尔曲线。

以下公式中：B(t)为t时间下 点的坐标；

P0为起点,Pn为终点,Pi为控制点

一阶贝塞尔曲线(线段)：

![img](http://hi.csdn.net/attachment/201008/28/0_1282984310y353.gif)

![img](https://images0.cnblogs.com/blog/500577/201306/21151949-bbe8b7e8a0b14409a189dc32e0420423.gif)

意义：由 P0 至 P1 的连续点， 描述的一条线段

二阶贝塞尔曲线(抛物线)：

![img](http://hi.csdn.net/attachment/201008/28/0_1282984320awS6.gif)

![img](https://images0.cnblogs.com/blog/500577/201306/21152016-1df7ccd4da8e4e8a86cf72772da8af42.gif)

原理：由 P0 至 P1 的连续点 Q0，描述一条线段。
      由 P1 至 P2 的连续点 Q1，描述一条线段。
      由 Q0 至 Q1 的连续点 B(t)，描述一条二次贝塞尔曲线。

经验：P1-P0为曲线在P0处的切线。

三阶贝塞尔曲线：

![img](http://hi.csdn.net/attachment/201008/28/0_1282984326C3m1.gif)

![img](https://images0.cnblogs.com/blog/500577/201306/21152048-9b5dee31b19349428c453b8bd5e20a3d.gif)

通用公式：

![img](http://hi.csdn.net/attachment/201008/28/0_1282984842iZn0.gif)

高阶贝塞尔曲线：

4阶曲线：

![img](https://images0.cnblogs.com/blog/500577/201306/21152111-c41a9b4fcb534449a8687d940dcfccbf.gif)

5阶曲线：

![img](https://images0.cnblogs.com/blog/500577/201306/21152142-50345f346c684ef68c5500e3a8e91cc0.gif)



--------------------------------------------------------------
### b-spline的学习网址



对b-spline的介绍网址：
http://www.qiujiawei.com/b-spline-1/

根据上面的网址，找到下面的讲义，这个讲义，内容已经说的很清楚了：
http://www.cs.mtu.edu/~shene/COURSES/cs3621/NOTES/

基本上按照顺序对b-spline的内容读了一次，但其实不够的，最好还是对前因后果都读一下会比较前面。

学习理解
b-spline是一种可以更灵活的表示曲线的数学模型，是对bezier曲线的继承发展。
主要的概念有：knots，control point，degree。

knots
b-spline的定义域是[0,1]之间，而knots是将定义域进行划分的，分成多段子定义域。

degree
degree这个我理解的不深，不好解析。

basic function
b-spline由一系列的basic function组成的，degree的不同，basic function的定义域也不同。

仅仅通过knots，degree就可以计算出basic function，也是系数。
http://www.cs.mtu.edu/~shene/COURSES/cs3621/NOTES/spline/B-spline/bs-basis.jpg

递归形式如下：


control points
control points影响曲线的shape，basic function，得到定义域内某个值计算出来的point，密集的插值就可以得到一条曲线了。
具体的插值公式为：


所以，当knots确定，degree确定，basic function也就确定了，即系数函数与control point无关。

knots，degree，control point的数量必须满足计算关系：
假设knots的数量为m，degree的值为p，control point的数量为n，则：
m=n+p+1

现有代码
在github上有js版的代码，自己用浏览器控制台执行验证过，确实是可以的，其verify是通过的。
js版b-spline曲线计算代码

动手翻译系数计算函数
虽然已经有了现有代码，可以翻译为c++后直接使用，但为了更好的掌握这个知识，还是自己动手实现一遍系数计算的过程。
参考这里的伪代码：
http://www.cs.mtu.edu/~shene/COURSES/cs3621/NOTES/spline/B-spline/bspline-curve-coef.html

重要的是对着图去看和理解代码：
http://www.cs.mtu.edu/~shene/COURSES/cs3621/NOTES/spline/B-spline/bspline-triangle.jpg


测试的数据用的是：
http://www.cs.mtu.edu/~shene/COURSES/cs3621/NOTES/spline/B-spline/bspline-ex-1.html



用opencv图形验证效果(test)
用了基本的计算系数的函数，就可以进行插值了，用opencv的图形来进行操作与显示。

思路
1 设定好degree，以及knots数组
2 创建一个500*500的空白图
3 鼠标在空白图上点击若干个控制点，数量满足要求：m=n+1+p
如果选多了，则只取前面的点
4 选够了控制点后，双击鼠标左键，进行插值，并将结果显示到界面中；
如果没有选够，则提示信息。





### AGG 之贝塞尔插值 :  控制点(中值+ 平移)  一种非常简单的多边形平滑方法

A very simple method of smoothing polygons 一种非常简单的多边形平滑方法

翻译：唐风

之前 comp.graphic.algorithms 上有一个讨论，是关于怎么样使用曲线对多边形进行插值处理，使得最终产生的曲线是光滑的而且能通过所有的顶点。Gernot Hoffmann 建议说使用著名的 B-Spline 来进行插值。这里有他当时的文章。B-Spline 在这里效果很好，它看起来就像是一个固定在多边形顶点上的橡皮尺（elastic ruler）。


spline_polygon1   spline_polygon2

 

bezier_interpolation但我有个大胆的推测，我觉得肯定还存在更简单的方法。比如，使用三次贝塞曲线(cubic Bezier)进行近似。贝塞尔曲线有两个固定点（起点和终点），另加两个决定曲线形状的控制点(CP）。关于贝塞尔曲线的更多知识可以在搜索引擎中找到，比如，你可以参考 Paul Bourke 的站点。现在给贝塞尔曲线的锚点（固定点），也就是多边形的某一对顶点，那么问题是，我们怎么计算控制点的位置？我运行 Xara X 然后画出了右边这个图形，这很简单，所以我决定尝试下计算出它们的坐标。很显然，多边形两条相邻边的两个控制点与这两个控制点之间的顶点应该在一条直线上，只有这样，两条相邻的插值曲线才能平滑地连接在一起。所以，这两个控制点应该是相对于顶点是对称的，不过，也不全是……，因为真正的对称就要求它们与中心点的距离应该是相等的，但对于我们的情况中并不完全是这样的。一开始，我试着先算出多边形两条边的角平分线，然后把控制点放在这条角平分线的垂直线上。但从图上可以看到，控制点的连线并不会总是垂直于角平分线的。

 

 

最终，我找到一个非常简单的办法，不需要任何复杂的数学计算。首先，我们计算出多边形所有边线的中点，Ai。

bezier_interpolation_s1
![1585892960788](http://images.cnblogs.com/cnblogs_com/liyiwen/WindowsLiveWriter/AGG_11435/bezier_interpolation_s1.jpg)




然后连接起相邻边中点，得到很多线段，记为 Ci 。并用图记的方法计算出 Bi 点。

bezier_interpolation_s2
![1585892960788](http://images.cnblogs.com/cnblogs_com/liyiwen/WindowsLiveWriter/AGG_11435/bezier_interpolation_s2.jpg)

 

 

最后一步，只需要简单地将 Ci 进行平移，平移的路径就是每条线段上 Bi 到对应顶点的路径。就这样，我们计算出了贝塞尔曲线的控制点，平滑的结果看起来也很棒。

bezier_interpolation_s3

![1585892960788](http://images.cnblogs.com/cnblogs_com/liyiwen/WindowsLiveWriter/AGG_11435/bezier_interpolation_s3_thumb.jpg)

 

这里还可以做一点小小的改进，因为我们已经得到了一条决定控制点的直线，所以，我们可以根据需要，使控制点在这条直线上移动，这样可以改变插值曲线的状态。我使用了一个与控制点和顶点初始距离相关的系数 K ，用来沿直线移动控制点。控制点离顶点越远，图形看起来就越锐利。

bezier_interpolation_s4
![1585892960788](http://images.cnblogs.com/cnblogs_com/liyiwen/WindowsLiveWriter/AGG_11435/bezier_interpolation_s4_thumb.jpg)



### B-样条基函数：定义 （B-spline Basis Functions: Definition）

  贝塞尔基函数用作权重。*B-*样条基函数也一样；但更复杂。但是它有两条贝塞尔基函数所没有的特性，即*(1)*定义域被节点细分（*subdivided*）； *(2)* 基函数不是在整个区间非零。实际上，每个*B*样条基函数在附近一个子区间非零，因此，*B-*样条基函数相当*“*局部*”*。

​    设*U* 是*m* *+ 1*个非递减数的集合，*u**0* *<= \*u*2 <= \*u*3 <= ... <= \*um**。*ui*称为**节点**（*knots*）*,* 集合*U* 称为**节点向量**（*knot vector*）*,* 半开区间*[\*ui\*, \*ui\*+1)* 是第*i*个节点区间（*knot span*）。注意某些*ui*可能相等，某些节点区间会不存在。如果一个节点 *ui* 出现 *k* 次 *(*即，*ui* *= \*ui\*+1 = ... = \*ui+k\*-1),* 其中 *k* *> 1, \*ui** 是一个重复度（*multiplicity*）为*k* 的多重节点，写为 *ui**(\*k*)*。 否则，如果*ui*只出现一次，它是一个简单节点。如果节点等间距*(*即， *ui**+1* *- \*ui** 是一个常数，对 *0 <= \*i* <= \*m* - 1)*，节点向量或节点序列称为均匀的；否则它是非均匀的。

​    节点可认为是分隔点，将区间*[\*u*0, \*um\*]*细分为节点区间。所有*B-*样条基函数被假设定义域在*[\*u*0, \*um\*]*上。在本文中，我们经常使用*u**0* *= 0*和*um* *= 1*，所以定义域是闭区间*[0,1]*。

​    为了定义*B-*样条基函数，我们还需要一个参数，基函数的次数（*degree*）*p*，第*i*个*p*次*B-*样条基函数，写为*Ni,p**(\*u*)*，递归定义如下：



 

 

![img](http://www.cs.mtu.edu/~shene/COURSES/cs3621/NOTES/spline/B-spline/bs-basis.jpg)

 

​       上述公式通常称为*Cox-de Boor*递归公式。 这个定义看起来很复杂；但是不难理解。如果次数（*degree*）为零（即， *p* *= 0*），这些基函数都是阶梯函数，这也是第一个表达式所表明的。即，如果*u*是在第*i*个节点区间*[\*ui\*, \*ui\*+1)*上基函数*Ni**,0**(\*u*)*是*1*。 例如，如果我们有四个节点*u**0* *= 0, \*u*1 = 1, \*u*2 = 2*和 *u**3* *= 3,* 节点区间 *0, 1* 和*2*是*[0,1), [1,2), [2,3)*，*0*次基函数是*N**0,0**(\*u*) = 1* 在 *[0,1)* ，在其它区间是*0*；*N**1,0**(\*u*) = 1* 在 *[1,2)*上，在其它区间是*0*；*N**2,0**(\*u*) = 1*在*[2,3)*上，其它区间是*0*。如下图所示：

![img](http://www.cs.mtu.edu/~shene/COURSES/cs3621/NOTES/spline/B-spline/bs-basis-0.jpg) 

 

​       为了理解*p*大于*0*时计算*Ni,p**(\*u*)*的方法，我们使用三角计算格式。所有节点区间列在左边（第一）列，所有零次基函数在第二列。见下图。

*![img](http://www.cs.mtu.edu/~shene/COURSES/cs3621/NOTES/spline/B-spline/bs-scheme.jpg)*

 

​        为了计算*Ni**,1**(\*u*)*，需要*Ni**,0**(\*u*)*和*Ni**+1,0**(\*u*)*。因此，我们可以计算*N**0,1**(\*u*), \*N*1,1(\*u*), \*N*2,1(\*u*), \*N*3,1(\*u*)* 等等。所有这些*Ni**,1**(\*u*)*写在第三列。一旦所有*Ni**,1**(\*u*)*计算完毕，我们可以计算*Ni**,2**(\*u*)*并将其放在第四列。继续这个过程直到所有需要的*Ni**,\*p***(\*u*)*的计算完毕。

​        上面我们获得了针对节点向量 *U* *= { 0, 1, 2, 3 }*的*N**0,0**(\*u*), \*N*1,0(\*u*)*和*N**2,0**(\*u*)* 。现在计算*N**0,1**(\*u*)*和*N**1,1**(\*u*)*。要计算*N**0,1**(\*u*)*，因为*i* *= 0*和*p* *= 1*，从定义出发有

*![img](http://www.cs.mtu.edu/~shene/COURSES/cs3621/NOTES/spline/B-spline/bs-basis-example-1-1.jpg)*

 

因为*u**0* *= 0, \*u*1 = 1*和*u**2* *= 2,*上式变为

*![img](http://www.cs.mtu.edu/~shene/COURSES/cs3621/NOTES/spline/B-spline/bs-basis-example-1-2.jpg)*

 

因为*N**0,0**(\*u*)*在*[0,1)*上非零且*N**1,0**(\*u*)*在*[1,2)*上非零，如果*u*在*[0,1)*上 *(\*resp.\*, [1,2) ),* 只有*N**0,0**(\*u*) (\*resp.\*, \*N*1,0(\*u*) )*对*N**0,1**(\*u*)*有贡献。因此，如果*u* 在*[0,1)*上*, \*N*0,1(\*u*)* 是*uN**0,0**(\*u*) = \*u**而如果*u* 在*[1,2)*上*, \*N*0,1(\*u*)*是 *(2 - \*u*)\*N*1,0(\*u*) = (2 - \*u*)*。相似的计算得到*N**1,1**(\*u*) = \*u* - 1*如果*u* 在*[1,2)*上*,* 而*N**1,1**(\*u*) = 3 - \*u** 如果 *u* 在*[2,3)*上。下图中，黑色和红色线分别是*N**0,1**(\*u*)*和  **N\*1,1(\*u*)*。注意*N**0,1**(\*u*) (\*resp.\*, \*N*1,1(\*u*))*在*[0,1)* 和*[1,2)* 上*(\*resp.\*, [1,2)* 和 *[2,3))*是非零的。

*![img](http://www.cs.mtu.edu/~shene/COURSES/cs3621/NOTES/spline/B-spline/bs-ex-1-d1.jpg)*

 

一旦获得*N**0,1**(\*u*)*和*N**1,1**(\*u*)*，可以计算*N**0,2**(\*u*)*。由定义得到下式*:*

*![img](http://www.cs.mtu.edu/~shene/COURSES/cs3621/NOTES/spline/B-spline/bs-basis-example-1-3.jpg)*

 

代入节点值得到

*![img](http://www.cs.mtu.edu/~shene/COURSES/cs3621/NOTES/spline/B-spline/bs-basis-example-1-4.jpg)*

 

注意 *N**0,1**(\*u*)* 在 *[0,1)*和*[1,2)*上非零而*N**1,1**(\*u*)* 在*[1,2)* 和 *[2,3)*上非零。因此，我们有三种情况要考虑：

 

1*. u* 在 *[0,1)*上*:*    这种情况，只有*N**0,1**(\*u*)*对*N**0,2**(\*u*)*的值有贡献。因此，*N**0,1**(\*u*)*是*u**,* 得到

![img](http://www.cs.mtu.edu/~shene/COURSES/cs3621/NOTES/spline/B-spline/bs-basis-example-1-5.jpg) 

2*. u* 在*[1,2)*上*:*    这种情况， *N**0,1**(\*u*)*和*N**1,1**(\*u*)*都对 *N**0,2**(\*u*)*有贡献。因此*N**0,1**(\*u*) = 2 - \*u** 且*N**1,1**(\*u*) = \*u* - 1* 在*[1,2)*上*,*得到 

*![img](http://www.cs.mtu.edu/~shene/COURSES/cs3621/NOTES/spline/B-spline/bs-basis-example-1-6.jpg)*

 

   【译注：上式中间的式子的第二项应为：*0.5(3-u)(u-1)*】

\3. *u* 在 *[2,3)*上*:*    这种情况，只有*N**1,1**(\*u*)*对 *N**0,2**(\*u*)*有贡献。因此*N**1,1**(\*u*) = 3 - \*u** 在*[2,3)*上，得到*,*



![img](http://www.cs.mtu.edu/~shene/COURSES/cs3621/NOTES/spline/B-spline/bs-basis-example-1-7.jpg) 

 

​    如果我们画出上述三种情况的曲线段，我们会看到两个相邻曲线段连接起来形成了在节点上的曲线。更确切地，第一种和第二种情况的曲线段在*u* *= 1*处连接起来，而第二种和第三种情况的曲线段在*u* *= 2*处连接起来。注意合成曲线是光滑的，但是如果节点向量包含多重节点通常就不是这样的。

 

![img](http://www.cs.mtu.edu/~shene/COURSES/cs3621/NOTES/spline/B-spline/bs-ex-1-d2.jpg)

 

 *![img](http://www.cs.mtu.edu/~shene/COURSES/cs3621/NOTES/GrLine1.gif)*

 两个重要的观察

​       因为 *Ni**,1**(\*u*)* 是从 *Ni**,0**(\*u*)* 和 *Ni**+1,0**(\*u*)*计算的而 因为*Ni**,0**(\*u*)*和*Ni**+1,0**(\*u*)* 在区间*[\*ui\*, \*ui\*+1)*和*[\*ui\*+1, \*ui\*+2)*分别是非零的，*Ni**,1**(\*u*)* 在这两个区间都是非零的。换句话说，*Ni**,1**(\*u*)*在*[\*ui\*, \*ui\*+2)*上是非零的。相似地，因为 *Ni**,2**(\*u*)* 依赖于*Ni**,1**(\*u*)* 和*Ni**+1,1**(\*u*)*且因为这两个基函数在*[\*ui\*, \*ui\*+2)*和*[\*ui\*+1, \*ui\*+3)*分别是非零的，*Ni**,2**(\*u*)*在*[\*ui\*, \*ui\*+3)*上非零。总之，为确定基函数*Ni,p**(\*u*),* 的非零定义域，可以追溯到三角计算格式直到回到第一列。例如，假设我们想找到 *N**1,3**(\*u*)*的非零定义域。基于上述讨论，我们可从西北和西南方向追溯直到第一列为止，如下图中蓝色虚线所示。因此 *N**1,3**(\*u*)*在 *[\*u*1, \*u*2), [\*u*2, \*u*3), [\*u*3, \*u*4)* 和*[\*u*4, \*u*5)*上是非零的。或，相等地，它在*[\*u*1, \*u*5)*上非零。*.*

*![img](http://www.cs.mtu.edu/~shene/COURSES/cs3621/NOTES/spline/B-spline/bs-back.jpg)*

 

总之，我们有下列观察：

​    **基函数 Ni,p(u)** **在[ui, ui+p+1)****上非零。或，相等地，Ni,p(u)** **在 p+1****个节点区间[ui, ui+1), [ui+1, ui+2), ..., [ui+p, ui+p+1)****上非零。**

​      接着，我们看相反的方向。给定一个节点区间*[\*ui\*, \*ui\*+1),*我们想知道哪个基函数会在计算中使用这个区间。我们可以以这个节点区间开始并画一个西北界限箭头和一个西南界限的箭头。所有封闭在楔形里的基函数使用 *Ni**,0**(\*u*)*（为什么？）因此在该区间是非零的。因此，所有在*[\*ui\*, \*ui\*+1)*上非零的*p* 次基函数是这个楔形和包含所有*Ni,p**(\*u*)* 的列的交集。实际上，这一列和两个箭头形成一个等边三角形，而这一列是垂直边。 从 *Ni**,0**(\*u*)* 数到 *Ni,p**(\*u*)* 有*p**+1*列。因此，等边三角形的垂直边至多有*p**+1* 项，即 *Ni,p**(\*u*), \*Ni\*-1,\*p*(\*u*), \*Ni\*-2,\*p*(\*u*), ..., \*Ni-p\*+2,\*p*(\*u*), \*Ni-p\*+1,\*p*(\*u*)* 和*Ni-p**,\*p***(\*u*)*。

*![img](http://www.cs.mtu.edu/~shene/COURSES/cs3621/NOTES/spline/B-spline/bs-non-0.jpg)*

 

​      让我们看上图。为了找到所有*3*次在 *[\*u*4, \*u*5)* 上非零的基函数，画出两个箭头和所有在垂直边的函数是我们想要的。这个例子，是*N**1,3**(\*u*), \*N*2,3(\*u*), \*N*3,3(\*u*),* 和*N**4,3**(\*u*).*用黄色三角表示。蓝色 *(\*resp.\*,* 红色*)* 三角显示的是在*[\*u*3, \*u*4) (\*resp.\*, [\*u*2, \*u*3) )*上非零的*3*次基函数。注意在*[\*u*2, \*u*3)*上只有*3*个*3*次基多项式。*.*

​      总之，我们观察到下列特性：

​    **在任何一个节点区间 [ui, ui+1),** **最多有 p+1****个p** **次基函数非零，即：Ni-p,p(u), Ni-p+1,p(u), Ni-p+2,p(u), ..., Ni-1,p(u)** **和 Ni,p(u),**

 

 系数的意义是什么*?*

​    最后，让我们研究下*Ni,p**(\*u*)*定义中系数的意义。当计算 *Ni,p**(\*u*)* 时，它使用*Ni,p**-1**(\*u*)*和*Ni**+1,\*p*-1**(\*u*)*。前者在 *[\*ui\*, \*ui+p\*)*上非零。如果*u* 是在这个半开区间，那么*u* *- \*ui** 是*u* 和这个区间左端之间的距离，区间长度是*ui+p* *- \*ui\*,* ，而*(\*u* - \*ui\*) / (\*ui+p\* - \*ui\*)* 是上述距离的比且在*0*和*1*之间。见下图。第二项，*Ni,p**-1**(\*u*)*，在*[\*ui\*+1, \*ui+p\*+1)*上非零。如果*u* 在该区间，那么*ui+p**+1* *- \*u** 是 *u* 到该区间右端的距离，*ui+p**+1* *- \*ui\*+1*是区间长度，而*(\*ui+p\*+1 - \*u*) / (\*ui+p\*+1 - \*ui\*+1)* 是这两个距离的比且值在*0*和*1*之间。因此*, \*Ni,p\*(*u\*)* 是*Ni,p**-1**(\*u*)* 和*Ni**+1,\*p*-1**(\*u*)*的线性组合，有两个系数，都在 *u*上是线性的，在*0*和*1*之间。

 

![img](http://www.cs.mtu.edu/~shene/COURSES/cs3621/NOTES/spline/B-spline/division-of-u.jpg)

 

### B-spline Curves 学习之前言

 <https://www.cnblogs.com/icmzn/p/5100740.html>

