//TESTS
CVille v1("Toulon", 0, 1), v2("Toulouse", 0, 2), v3("Renes", 0, 3), v4("Bordeau", 0, 4);
/*v1.Print();
v2.Print();
v3.Print();
v4.Print();

CVille V1[2] = {v1, v2};
CChemin<CVille> c1(V1, 2);
c1.Print();
CVille V2[2] = {v3, v4};
CChemin<CVille> c2(V2, 2);
c2.Print();

CChemin<CVille> C[2] = {c1, c2};
// CPopulation< CChemin<CVille> > p(C, 2);
p.Print();

cout<<"Fitness 1:"<<c1.Fitness()<<endl;
cout<<"Fitness 2:"<<c2.Fitness()<<endl;*/

CVille V4[4] = {v1, v2, v3, v4};
CChemin<CVille> c3(V4, 4);
CVille V5[4] = {v4, v3, v2, v1};
CChemin<CVille> c4(V5, 4);

CChemin<CVille> C1[2] = {c3, c4};
CPopulation< CChemin<CVille> > p1(C1, 2);

// p1.Print();
// Mutation Mut;
// Mut.start(&p1);
// p1.Print();

// p1.Print();
Elitisme Eli(1);
CPopulation< CChemin<CVille> > p2 = Eli.start(p1);
// p2.Print();

CPopulation< CChemin<CVille> > p3;
p3 = p1 + p1;
// cout<<"AH"<<endl;
// p3.Print();

// cout<<"AH"<<endl;
// Selection Sel(2);
// CPopulation< CChemin<CVille> > p4 = Sel.roulette(p3);
// p4.Print();

CPopulation< CChemin<CVille> > p5 = p1;
// cout<<"p5"<<endl;
// p5.Print();
Croisement Cro;
CPopulation< CChemin<CVille> > p6 = Cro.start(p3);
// cout<<"p6"<<endl;
// p6.Print();

CPopulation< CChemin<CVille> > p7;
p7.init();
