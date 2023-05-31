#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define d double
using namespace std;
//f means function,p means point
//#* means the return value,so we could easily search them

double f3p1(double pc, double Vc, double qmc) {
	//燃烧室燃气停留时间#taoc
	//Vc=燃烧室容积,pc=燃气平均密度,qmc=燃气流量q
	d taoc = pc * Vc * 1.0 / qmc * 1.0;
	return taoc;
}

double f3p2(double Vc, double At) {
	//求特征长度#L
	//Vc=燃烧室容积,At=喉部面积
	d L = Vc * 1.0 / At * 1.0;
	return L;
}

d f3p3(d qmc, d Ac) {
	//求燃烧室质量流量密度#qmdc
	//qmc=质量流量,Ac=燃烧室截面积
	d qmdc = qmc / Ac;
	return qmdc;
}

d f3p4(d Dt, d pc) {
	//求离心式喷注器收缩比#eplisonc
	//Dt=喉部直径 pc=燃烧室压力
	d eplisonc = 5.0 / sqrt(pc * Dt);
	return eplisonc;
}

d f3p5(d Vc, d Vc2, d Ac) {
	//计算圆筒段长度#Lc1
	//Vc=圆筒段容积 Vc2=喷管收敛段容积 Ac燃烧室截面积
	d Lc1 = (Vc - Vc2) / Ac;
	return Lc1;
}

vector<d> shrinkstimulate(d k, d p, d Rt, d Rc, d eplisonc) {
	//模拟计算收敛段尺寸数据
	//R1上端圆弧半径,R2下端圆弧半径,Rt喉部半径,Rc圆筒段半径,eplisonc收缩比
	//设R1=k*Rt,R2=p*Rc=p*(sqrt(eplisonc))*Rt
	//推荐Rt<R1<2*Rt,R2=2.5*Rc
	vector<d>a;
	d sec = sqrt(eplisonc);
	d R1 = k * Rt;
	d R2 = p * (sec) * Rt;
	//几何关系计算收敛段长度Lc2
	d Lc2;
	Lc2 = Rt * sqrt(pow(k + p * sec, 2) - pow((p - 1) * sec + k + 1, 2));
	a.push_back(Lc2);
	//计算R1与R2圆弧切点距离喉部的距离(R2段水平长度)h,R1段水平长度H
	d h, H;
	h = k * Lc2 * 1.0 / (k + p * sec) * 1.0;
	H = Lc2 - h;
	a.push_back(h);
	a.push_back(H);
	//计算R1与R2切点距离燃烧室中轴线的距离y
	d y;
	y = k * Rt + Rt - sqrt(k * k * Rt * Rt - h * h);
	a.push_back(y);

	return a;
}

int main() {

}
