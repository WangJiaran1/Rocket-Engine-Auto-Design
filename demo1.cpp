#include<iostream>
#include<cmath>
using d=double;

class TrustChamber{
private:
    double m_Isp;
    double m_Trust;
    double m_ChamberPressure;
    double m_ChamberTemperature;
    d qmc;          //Fluent mass
    d Cstar;        //Characteristic velocity
    d At;           //Area of throat
    d Ae;           //Area of exhaust
    d Dt;           //Dt depends on At
    d qmdc;         //Fluent mass density
    d k;            //Specific heat ratio
    d R;            //Gas constant
    d ThroatPressue;
    d ThroatVelocity;
    d ExhaustVelocity;
    d ExhaustPressure;
    d ExhaustTemperature;
    d Vi;           //specific volume of the gas at the nozzle inlet
    d Vt;           //specific volume of the gas at the throat
    d Ve;           //specific volume of the gas at the exhaust
public:
    TrustChamber(){
        std::cout<<"Maybe you should input some digit so we can caculate them.\n";
    }
    // TrustChamber(double Isp,double Trust,double CP)
    //     :m_Isp(Isp),m_Trust(Trust),m_ChamberPressure(CP){
    //     std::cout<<"Not available now.\n";
    // }
    TrustChamber(double Trust,double CP,double CT)
        :m_Trust(Trust),m_ChamberPressure(CP),m_ChamberTemperature(CT){
        m_Isp=300;  //default
        k=1.30;     //default
        R=355.4;    //default
        ExhaustPressure=0.002549;//default
        ThroatPressue=m_ChamberPressure*std::pow(2/(k+1),(k/(k-1)));
        std::cout<<"ThroatPressue: "<<ThroatPressue<<'\n';
        ThroatVelocity=std::sqrt((2*k/(k+1))*R*CT);
        std::cout<<"ThroatVelocity: "<<ThroatVelocity<<'\n';
        ExhaustVelocity=sqrt((2*k/(k-1))*R*CT*(1-pow(ExhaustPressure/CP,(k-1)/k)));
        std::cout<<"ExhaustVelocity: "<<ExhaustVelocity<<'\n';       
        qmc=Trust/ExhaustVelocity;
        std::cout<<"qmc: "<<qmc<<'\n';
        Vi=R*CT/(CP*1000000);
        Vt=Vi*pow((k+1)/2,1/(k-1));
        Ve=Vi*pow(CP/ExhaustPressure,1/k);
        std::cout<<"Vi: "<<Vi<<"  Vt: "<<Vt<<"  Ve: "<<Ve<<'\n';
        At=qmc*Vt/ThroatVelocity;
        Ae=qmc*Ve/ExhaustVelocity;
        std::cout<<"At: "<<At<<"  Ae: "<<Ae<<'\n';
        ExhaustTemperature=CT*pow(ExhaustPressure/CP,(k-1)/k);
        std::cout<<"ExhaustTemperature: "<<ExhaustTemperature<<'\n';
    }

    ~TrustChamber(){
        //std::ofstream
    }

};

int main(){
    // d Isp,Trust,CP;
    // std::cout<<"Input Isp: ";
    // std::cin>>Isp;
    // std::cout<<"Input Trust: ";
    // std::cin>>Trust;
    // std::cout<<"Input ChameberPressure: ";
    // std::cin>>CP;
    {
        TrustChamber trustchamber(5000.0,2.068,2800.0);
        //When leave this namespace ,the destruct function will be called.
    }
}