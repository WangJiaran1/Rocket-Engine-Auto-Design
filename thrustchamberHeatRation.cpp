#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define d double
using namespace std;

d f3p27(d qk, d qr) {
	//传给室壁的热流密度qs
	//对流热密度qk 辐射热流密度qr
	d qs = qk + qr;
	return qs;
}

d f3p28(d hg, d Tst, d Twg) {
	//燃气对流传热的热流密度qk
	//Tst近壁层燃气总温 Twg气体壁面温度
	d qk = hg * (Tst - Twg);
	return qk;
}

d f3p29(d epsilonw, d spsilong, d Tg, d Twg) {
	//斯蒂芬玻尔兹曼定律
	//燃气的辐射传热qt
	//壁面有效黑度epsilonw,温度Tg,温度Tg时的燃气发射率epsilong
	//ag温度为Tg时燃气吸收率 c0黑体辐射系数
	d c0 = 5.67;
	d qr = epsilonw * epsilong * c0 * pow((Tg / 100), 4) - epsilonw * ag * c0 * pow((Tg / 100), 4);
	return qr;
}

//后面不写变量介绍了 书上对应吧

d f3p30(d epsilonw, d spsilong, d Tg, d Twg) {
	//采用外冷却时忽略壁面辐射的f3p29
	d qr = epsilonw * epsilong * c0 * pow((Tg / 100), 4);
	return qr;
}

d f3p31(d hg, d Tst, d Twg, d qr) {
	//假定燃气对壁的传热系数hgp(hg')
	d hgp;
	hgp = hg + qr / (Tst - Twg);
	return hgp;
}

d f3p32(d qs, d hgp, d Tst, d Twg) {
	//此时热流密度计算公式
	d qs = hgp * (Tst - Twg);
	return qs;
}

d f3p33(d lambdaw, d deltaw, d Twg, d Twf) {
	//热传导过程表示
	d q = (lambdaw / deltaw) * (Twg - Twf);
	return q;
}

d f3p34(d Twf, d Tf, d hf) {
	//热流由推力室壁传给冷却剂
	d q = hf * (Twf - Tf);
	return q;
}

d f3p35(d lambdaw, d deltaw, d Tst, d Tf, d hgp, d af) {
	//f3p32~34解得
	d q = (1 / ((1 / hgp) + (deltaw / lambdaw) + (1 / af))) * (Tst - Tf);
	return q;
}

d f3p33(d Twg, d lambdaw, d deltaw, d q) {
	//f3p33推导
	d Twf = Twg - q * deltaw / lambdaw;
	return Twf;
}