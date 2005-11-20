printf("digraph G {\n");
printf("\tnode [style=filled, fontname=arial, fontsize=12, fillcolor=yellow, color=darkviolet]\n");

printf("\tnOsTATE [shape=point style=filled fillcolor=black color=black];\n");

printf("\t%s [label=\"%s\", shape=Mrecord];\n","Test1","Test1");
printf("\t%s [label=\"%s\", shape=Mrecord];\n","Test2","{Test2 | n12345\\nhjgjh gjhg}");

printf("\tnOsTATE->Test1\n");
printf("\tTest2->Test1\n");


printf("}\n");
