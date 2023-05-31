#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define d double
using namespace std;

d f3p12(d p, d An, d pin, d pc, d win) {
	//求喷嘴质量流量#qmth
	//p=液体密度,An喷孔面积,pin喷嘴入口压强	pc燃烧室压强 win入口速度
	d qmth;
	qmth = p * An * sqrt(2 * ((pin - pc) * 1.0 / p * 1.0 + win * win / 2.0));
	//另外这里还有压降pn公式
	d pn = pin - pc;
	return qmth;
}

d f3p13(d An, d p, d pin, d pc) {
	//因为入口速度很多时候比较小，所有有时候可以忽略
	d qmth;
	qmth = An * sqrt(2 * p * (pin - pc));
	return qmth;
}

d f3p14(d qm, d qmth) {
	//因为喷嘴里面一般有能量损失，所以存在流量系数#miu
	//qm实际流量 qmth实际流量
	d miu;
	miu = qm / qmth;
	return miu;
}

d f3p15(d miu, d qm, d p, d pin, d pc) {
	//确定燃料和氧化剂喷嘴孔所需总面积#Ans
	//这个公式是转换过来的，原本等号左式是实际流量qm
	//miu流量系数 qm实际流量 p密度 pin喷嘴入口压强 pc燃烧室压强
	d Ans;
	Ans = qm * 1.0 / (miu * sqrt(2 * p * (pin - pc)));
	//发现这个公式其实就是f3p13和f3p14拼起来的
	return Ans;
}

//单组元气体直流喷嘴部分
d f3p18(d rouin, d pc, d pin, d gama, d miu, d w2, d An) {
	//气体直流喷嘴质量流量方程#qmh
	//miu流量系数，一般0.75~0.8 w2气体喷出速度 p2喷嘴出口截面气体密度 An喷嘴出口截面积
	//pin喷嘴入口气体压力 rouin喷嘴入口气体密度 gama比热比
	d p2;
	p2 = rouin * pow((pc / pin * 1.0), (1 / gama));
	d qmh;
	qmh = miu * w2 * An * p2;
	return qmh;
}

d f3p19(d pn, d pc) {
	//喷嘴入口气体压力#pin
	//pn喷嘴压降=pin-pc pc燃烧室压强,pin入口压强
	d pin = pc + pn;
	return pin;
}


d f3p20(d gama, d R, d T, d pc, d pin) {
	//气体喷出速度#w2
	//R喷嘴前气体常数 Tin喷嘴前气体总温 gama比热比
	d index = 2 * gama / (gama - 1);
	d w2;
	w2 = sqrt(index * R * T * (1 - pow((pc / pin * 1.0), (gama - 1) * 1.0 / gama * 1.0)));
	return w2;
}

d f3p21(d miu, d qmh, d rouin, d pc, d pin, d gama, d w2) {
	//喷嘴出口截面积#An
	//从f3p18和f3p20变形过来的
	d An;
	An = qmh * 1.0 / (miu * rouin * pow((pc * 1.0) / pin, 1.0 / gama) * w2);
	return An;
}

d f3p22(d miu, d qmh, d rouin, d pc, d pin, d gama) {
	//也是求An的
	d index1 = 2.0 * gama / (gama - 1);
	d index2 = (gama + 1.0) / gama;
	d temp = pc / pin;
	d An = qmh * 1.0 / (miu * sqrt(index1 * pin * rouin * (pow(temp, 2.0 / gama) - pow(temp, index2))));
	return An;
}

//单组元液体离心式喷嘴
d f3p23(d pin, d pc, d win, d wv, d wa, d wr, d p) {
	//能量守恒推出的流动过程方程
	//win切向入口内流速,wv喷嘴出口切向速度分量,wa喷嘴出口轴向速度分量
	//wr喷嘴出口径向速度分量,p密度
	//pin+p*win*win/2.0=pc+p*wv*wv/2.0+p*wa*wa/2.0+p*wr*wr/2.0;
	return 0;
}

d f3p24() {
	//动量矩守恒方程
	//r切向孔半径 R过圆心与切向孔平行的直径到切向孔中轴线的距离
	//win*R=wv*r;
	return 0;
}

int main() {

}