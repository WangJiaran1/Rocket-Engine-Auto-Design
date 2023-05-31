#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define d double
using namespace std;

d f3p12(d p, d An, d pin, d pc, d win) {
	//��������������#qmth
	//p=Һ���ܶ�,An������,pin�������ѹǿ	pcȼ����ѹǿ win����ٶ�
	d qmth;
	qmth = p * An * sqrt(2 * ((pin - pc) * 1.0 / p * 1.0 + win * win / 2.0));
	//�������ﻹ��ѹ��pn��ʽ
	d pn = pin - pc;
	return qmth;
}

d f3p13(d An, d p, d pin, d pc) {
	//��Ϊ����ٶȺܶ�ʱ��Ƚ�С��������ʱ����Ժ���
	d qmth;
	qmth = An * sqrt(2 * p * (pin - pc));
	return qmth;
}

d f3p14(d qm, d qmth) {
	//��Ϊ��������һ����������ʧ�����Դ�������ϵ��#miu
	//qmʵ������ qmthʵ������
	d miu;
	miu = qm / qmth;
	return miu;
}

d f3p15(d miu, d qm, d p, d pin, d pc) {
	//ȷ��ȼ�Ϻ���������������������#Ans
	//�����ʽ��ת�������ģ�ԭ���Ⱥ���ʽ��ʵ������qm
	//miu����ϵ�� qmʵ������ p�ܶ� pin�������ѹǿ pcȼ����ѹǿ
	d Ans;
	Ans = qm * 1.0 / (miu * sqrt(2 * p * (pin - pc)));
	//���������ʽ��ʵ����f3p13��f3p14ƴ������
	return Ans;
}

//����Ԫ����ֱ�����첿��
d f3p18(d rouin, d pc, d pin, d gama, d miu, d w2, d An) {
	//����ֱ������������������#qmh
	//miu����ϵ����һ��0.75~0.8 w2��������ٶ� p2������ڽ��������ܶ� An������ڽ����
	//pin�����������ѹ�� rouin������������ܶ� gama���ȱ�
	d p2;
	p2 = rouin * pow((pc / pin * 1.0), (1 / gama));
	d qmh;
	qmh = miu * w2 * An * p2;
	return qmh;
}

d f3p19(d pn, d pc) {
	//�����������ѹ��#pin
	//pn����ѹ��=pin-pc pcȼ����ѹǿ,pin���ѹǿ
	d pin = pc + pn;
	return pin;
}


d f3p20(d gama, d R, d T, d pc, d pin) {
	//��������ٶ�#w2
	//R����ǰ���峣�� Tin����ǰ�������� gama���ȱ�
	d index = 2 * gama / (gama - 1);
	d w2;
	w2 = sqrt(index * R * T * (1 - pow((pc / pin * 1.0), (gama - 1) * 1.0 / gama * 1.0)));
	return w2;
}

d f3p21(d miu, d qmh, d rouin, d pc, d pin, d gama, d w2) {
	//������ڽ����#An
	//��f3p18��f3p20���ι�����
	d An;
	An = qmh * 1.0 / (miu * rouin * pow((pc * 1.0) / pin, 1.0 / gama) * w2);
	return An;
}

d f3p22(d miu, d qmh, d rouin, d pc, d pin, d gama) {
	//Ҳ����An��
	d index1 = 2.0 * gama / (gama - 1);
	d index2 = (gama + 1.0) / gama;
	d temp = pc / pin;
	d An = qmh * 1.0 / (miu * sqrt(index1 * pin * rouin * (pow(temp, 2.0 / gama) - pow(temp, index2))));
	return An;
}

//����ԪҺ������ʽ����
d f3p23(d pin, d pc, d win, d wv, d wa, d wr, d p) {
	//�����غ��Ƴ����������̷���
	//win�������������,wv������������ٶȷ���,wa������������ٶȷ���
	//wr������ھ����ٶȷ���,p�ܶ�
	//pin+p*win*win/2.0=pc+p*wv*wv/2.0+p*wa*wa/2.0+p*wr*wr/2.0;
	return 0;
}

d f3p24() {
	//�������غ㷽��
	//r����װ뾶 R��Բ���������ƽ�е�ֱ��������������ߵľ���
	//win*R=wv*r;
	return 0;
}

int main() {

}