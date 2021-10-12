int mx_sqrt(int x1) {
   unsigned int m, y, b, x, x2;
   if (x1 < 1)
      return 0;
   else
      x = (unsigned int) x1;
   x2 = x;
   m = 0x4000;
   y = 0;
   while (m != 0){
      b = y | m;
      y = y >> 1;
      if (x >= b) {
         x = x - b;
         y = y | m;
      }
      m = m >> 2;
   }
   if  (x2 == y * y)
      return y;
   else
      return 0;
}
