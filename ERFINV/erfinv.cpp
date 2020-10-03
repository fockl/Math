#include<stdio.h>
#include<math.h>
#include<chrono>

inline double table17(
    const double& t1,
    const double& p00, const double& p01, const double& p02, const double& p03, const double& p04, const double& p05, const double& p06,
    const double& q00, const double& q01, const double& q02, const double& q03, const double& q04, const double& q05, const double& q06){
  double t2 = t1*t1;
  double t4 = t2*t2;
  return (p00+p01*t1+p02*t2+p03*t1*t2+p04*t4+p05*t1*t4+p06*t2*t4)/(q00+q01*t1+q02*t2+q03*t1*t2+q04*t4+q05*t1*t4+q06*t2*t4);
}

inline double table37(
    const double& t1,
    const double& p00, const double& p01, const double& p02, const double& p03, const double& p04, const double& p05, const double& p06, const double& p07,
    const double& q00, const double& q01, const double& q02, const double& q03, const double& q04, const double& q05, const double& q06, const double& q07
    ){
  double t2 = t1*t1;
  double t4 = t2*t2;
  return (p00+p01*t1+p02*t2+p03*t1*t2+p04*t4+p05*t1*t4+p06*t2*t4+p07*t1*t2*t4)/(q00+q01*t1+q02*t2+q03*t1*t2+q04*t4+q05*t1*t4+q06*t2*t4+q07*t1*t2*t4);
}

inline double table57(
    const double& t1,
    const double& p00, const double& p01, const double& p02, const double& p03, const double& p04, const double& p05, const double& p06, const double& p07, const double& p08,
    const double& q00, const double& q01, const double& q02, const double& q03, const double& q04, const double& q05, const double& q06, const double& q07, const double& q08, const double& q09
    ){
  double t2 = t1*t1;
  double t4 = t2*t2;
  double t8 = t4*t4;
  return (p00+p01*t1+p02*t2+p03*t1*t2+p04*t4+p05*t1*t4+p06*t2*t4+p07*t1*t2*t4+p08*t8)/(q00+q01*t1+q02*t2+q03*t1*t2+q04*t4+q05*t1*t4+q06*t2*t4+q07*t1*t2*t4+q08*t8+q09*t1*t8);
}

inline double erfinv(double x){
  double a = abs(x);
  if(a>=1.0){
    return -1.0;
  }else if(a<=0.75){
    double t = x*x - 0.5625;
    return x*table17(
        t,

0.160304955844066229311e2,
-0.90784959262960326650e2,
0.18644914861620987391e3,
-0.16900142734642382420e3,
0.6545466284794487048e2,
-0.864213011587247794e1,
0.1760587821390590,

0.147806470715138316110e2,
-0.91374167024260313936e2,
0.21015790486205317714e3,
-0.22210254121855132366e3,
0.10760453916055123830e3,
-0.206010730328265443e2,
0.1e1
        );
  }else if(a <= 0.9375){
    double t = x*x - 0.87890625;
    return x*table37(
        t,

-0.152389263440726128e-1,
0.3444556924136125216,
-0.29344398672542478687e1,
0.11763505705217827302e2,
-0.22655292823101104193e2,
0.19121334396580330163e2,
-0.5478927619598318769e1,
0.237516689024448,

-0.108465169602059954e-1,
0.2610628885843078511,
-0.24068318104393757995e1,
0.10695129973387014469e2,
-0.23716715521596581025e2,
0.24640158943917284883e2,
-0.10014376349783070835e2,
0.1e1
        );
  }else{
    double t = 1.0/sqrt(-log(1.0-a));
    return table57(
        t,

0.10501311523733438116e-3,
0.1053261131423333816425e-1,
0.26987802736243283544516,
0.23268695788919690806414e1,
0.71678547949107996810001e1,
0.85475611822167827825185e1,
0.68738088073543839802913e1,
0.3627002483095870893002e1,
0.886062739296515468149,

0.10501266687030337690e-3,
0.1053286230093332753111e-1,
0.27019862373751554845553,
0.23501436397970253259123e1,
0.76078028785801277064351e1,
0.111815861040569078273451e2,
0.119487879184353966678438e2,
0.81922409747269907893913e1,
0.4099387907636801536145e1,
0.1e1
        )/copysign(t, x);
  }
}

int main(void){

  printf("%lf\n", erfinv(0.5));
  printf("%lf\n", erfinv(0.9));
  printf("%lf\n", erfinv(0.99));

  long long N = 1E8;

  std::chrono::system_clock::time_point start, end;
  start = std::chrono::system_clock::now();

  for(long long i=0; i<N; ++i){
    erfinv((double)i/N);
  }

  end = std::chrono::system_clock::now();

  double time = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0);
  printf("time %lf[ms]\n", time);

  return 0;
}
