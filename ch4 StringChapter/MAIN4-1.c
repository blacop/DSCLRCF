 /* main4-1.c ����bo4-1.c�������� */
 #include"c1.h"
 #include"c4-1.h"
 #include"bo4-1.c"
 void main()
 {
   int i,j;
   Status k;
   char s,c[MAXSTRLEN+1];
   SString t,s1,s2;
   printf("�����봮s1: ");
   gets(c);
   k=StrAssign(s1,c);
   if(!k)
   {
     printf("��������MAXSTRLEN(=%d)\n",MAXSTRLEN);
     exit(0);
   }
   printf("����Ϊ%d ���շ�%d(1:�� 0:��)\n",StrLength(s1),StrEmpty(s1));
   StrCopy(s2,s1);
   printf("����s1���ɵĴ�Ϊ: ");
   StrPrint(s2);
   printf("�����봮s2: ");
   gets(c);
   k=StrAssign(s2,c);
   if(!k)
   {
     printf("��������MAXSTRLEN(%d)\n",MAXSTRLEN);
     exit(0);
   }
   i=StrCompare(s1,s2);
   if(i<0)
     s='<';
   else if(i==0)
     s='=';
   else
     s='>';
   printf("��s1%c��s2\n",s);
   k=Concat(t,s1,s2);
   printf("��s1���Ӵ�s2�õ��Ĵ�tΪ: ");
   StrPrint(t);
   if(k==FALSE)
     printf("��t�нض�\n");
   ClearString(s1);
   printf("��Ϊ�մ���,��s1Ϊ: ");
   StrPrint(s1);
   printf("����Ϊ%d ���շ�%d(1:�� 0:��)\n",StrLength(s1),StrEmpty(s1));
   printf("��t���Ӵ�,�������Ӵ�����ʼλ��,�Ӵ�����: ");
   scanf("%d,%d",&i,&j);
   k=SubString(s2,t,i,j);
   if(k)
   {
     printf("�Ӵ�s2Ϊ: ");
     StrPrint(s2);
   }
   printf("�Ӵ�t�ĵ�pos���ַ���,ɾ��len���ַ���������pos,len: ");
   scanf("%d,%d",&i,&j);
   StrDelete(t,i,j);
   printf("ɾ����Ĵ�tΪ: ");
   StrPrint(t);
   i=StrLength(s2)/2;
   StrInsert(s2,i,t);
   printf("�ڴ�s2�ĵ�%d���ַ�֮ǰ���봮t��,��s2Ϊ:\n",i);
   StrPrint(s2);
   i=Index(s2,t,1);
   printf("s2�ĵ�%d����ĸ���t��һ��ƥ��\n",i);
   SubString(t,s2,1,1);
   printf("��tΪ��");
   StrPrint(t);
   Concat(s1,t,t);
   printf("��s1Ϊ��");
   StrPrint(s1);
   Replace(s2,t,s1);
   printf("�ô�s1ȡ����s2�кʹ�t��ͬ�Ĳ��ص��Ĵ���,��s2Ϊ: ");
   StrPrint(s2);
 }