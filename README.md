

[TOC]



 [贝塞尔曲线原理(简单阐述)](https://www.cnblogs.com/hnfxs/p/3148483.html)  <https://www.cnblogs.com/hnfxs/p/3148483.html>

参考: b-spline学习-系数计算及程序实践
https://blog.csdn.net/brightming/article/details/53953926

[AGG 之贝塞尔插值](https://www.iteye.com/blog/liyiwen-705489)https://www.iteye.com/blog/liyiwen-705489

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




