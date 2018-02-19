#include "Vec3D.h"
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
   Vec3D p1(2.999999999,3);
   Vec3D p2(2.999999998,3,0);
   if(p1==p2) cout<<"true";
   else cout<<"false";

   p1.show();
   p2.show();
   p1=p1;

   p1.show();
   p1.normalize();
   p1.show();
   cout<<p1.getMagnitude()<<" "<<p2.getMagnitude()<<endl;

}