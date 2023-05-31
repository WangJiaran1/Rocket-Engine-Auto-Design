#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define d double
using namespace std;
//f means function,p means point
//#* means the return value,so we could easily search them

double f3p1(double pc, double Vc, double qmc) {
	//ȼ����ȼ��ͣ��ʱ��#taoc
	//Vc=ȼ�����ݻ�,pc=ȼ��ƽ���ܶ�,qmc=ȼ������q
	d taoc = pc * Vc * 1.0 / qmc * 1.0;
	return taoc;
}

double f3p2(double Vc, double At) {
	//����������#L
	//Vc=ȼ�����ݻ�,At=�����
	d L = Vc * 1.0 / At * 1.0;
	return L;
}

d f3p3(d qmc, d Ac) {
	//��ȼ�������������ܶ�#qmdc
	//qmc=��������,Ac=ȼ���ҽ����
	d qmdc = qmc / Ac;
	return qmdc;
}

d f3p4(d Dt, d pc) {
	//������ʽ��ע��������#eplisonc
	//Dt=��ֱ�� pc=ȼ����ѹ��
	d eplisonc = 5.0 / sqrt(pc * Dt);
	return eplisonc;
}

d f3p5(d Vc, d Vc2, d Ac) {
	//����ԲͲ�γ���#Lc1
	//Vc=ԲͲ���ݻ� Vc2=����������ݻ� Acȼ���ҽ����
	d Lc1 = (Vc - Vc2) / Ac;
	return Lc1;
}

vector<d> shrinkstimulate(d k, d p, d Rt, d Rc, d eplisonc) {
	//ģ����������γߴ�����
	//R1�϶�Բ���뾶,R2�¶�Բ���뾶,Rt���뾶,RcԲͲ�ΰ뾶,eplisonc������
	//��R1=k*Rt,R2=p*Rc=p*(sqrt(eplisonc))*Rt
	//�Ƽ�Rt<R1<2*Rt,R2=2.5*Rc
	vector<d>a;
	d sec = sqrt(eplisonc);
	d R1 = k * Rt;
	d R2 = p * (sec) * Rt;
	//���ι�ϵ���������γ���Lc2
	d Lc2;
	Lc2 = Rt * sqrt(pow(k + p * sec, 2) - pow((p - 1) * sec + k + 1, 2));
	a.push_back(Lc2);
	//����R1��R2Բ���е������ľ���(R2��ˮƽ����)h,R1��ˮƽ����H
	d h, H;
	h = k * Lc2 * 1.0 / (k + p * sec) * 1.0;
	H = Lc2 - h;
	a.push_back(h);
	a.push_back(H);
	//����R1��R2�е����ȼ���������ߵľ���y
	d y;
	y = k * Rt + Rt - sqrt(k * k * Rt * Rt - h * h);
	a.push_back(y);

	return a;
}

int main() {

}
