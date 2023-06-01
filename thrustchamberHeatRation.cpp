#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define d double
using namespace std;

d f3p27(d qk, d qr) {
	//�����ұڵ������ܶ�qs
	//�������ܶ�qk ���������ܶ�qr
	d qs = qk + qr;
	return qs;
}

d f3p28(d hg, d Tst, d Twg) {
	//ȼ���������ȵ������ܶ�qk
	//Tst���ڲ�ȼ������ Twg��������¶�
	d qk = hg * (Tst - Twg);
	return qk;
}

d f3p29(d epsilonw, d spsilong, d Tg, d Twg) {
	//˹�ٷҲ�����������
	//ȼ���ķ��䴫��qt
	//������Ч�ڶ�epsilonw,�¶�Tg,�¶�Tgʱ��ȼ��������epsilong
	//ag�¶�ΪTgʱȼ�������� c0�������ϵ��
	d c0 = 5.67;
	d qr = epsilonw * epsilong * c0 * pow((Tg / 100), 4) - epsilonw * ag * c0 * pow((Tg / 100), 4);
	return qr;
}

//���治д���������� ���϶�Ӧ��

d f3p30(d epsilonw, d spsilong, d Tg, d Twg) {
	//��������ȴʱ���Ա�������f3p29
	d qr = epsilonw * epsilong * c0 * pow((Tg / 100), 4);
	return qr;
}

d f3p31(d hg, d Tst, d Twg, d qr) {
	//�ٶ�ȼ���ԱڵĴ���ϵ��hgp(hg')
	d hgp;
	hgp = hg + qr / (Tst - Twg);
	return hgp;
}

d f3p32(d qs, d hgp, d Tst, d Twg) {
	//��ʱ�����ܶȼ��㹫ʽ
	d qs = hgp * (Tst - Twg);
	return qs;
}

d f3p33(d lambdaw, d deltaw, d Twg, d Twf) {
	//�ȴ������̱�ʾ
	d q = (lambdaw / deltaw) * (Twg - Twf);
	return q;
}

d f3p34(d Twf, d Tf, d hf) {
	//�����������ұڴ�����ȴ��
	d q = hf * (Twf - Tf);
	return q;
}

d f3p35(d lambdaw, d deltaw, d Tst, d Tf, d hgp, d af) {
	//f3p32~34���
	d q = (1 / ((1 / hgp) + (deltaw / lambdaw) + (1 / af))) * (Tst - Tf);
	return q;
}

d f3p33(d Twg, d lambdaw, d deltaw, d q) {
	//f3p33�Ƶ�
	d Twf = Twg - q * deltaw / lambdaw;
	return Twf;
}