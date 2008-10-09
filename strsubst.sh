#!/bin/sh

for i in `find -name '*.cpp'`; do
 echo $i;
 if (! test -f $i.strsub) then
   mv $i $i.strsub;
 fi
 awk '
# Look for lines witch contain a string in "", but not for strings with _T(""

/\".*\"/ && ! /_T\(\".*\"/ {
# print $0;
  l = split ($0, a, "\"");
  for (i = 1; i <= l; i++)
  {
     if (i%2)
     {
	printf a[i];
     }
     else
     {
        printf "_T(\"%s\")",a[i];
     }
  }
  printf "\n";
}

# Line contains no strings OR _T(
!/\"*\"/ || /_T\(\"*\"/ {
  printf $0;
  printf "\n";
}
' $i.strsub > $i
# $i.strsub > $i
done;
