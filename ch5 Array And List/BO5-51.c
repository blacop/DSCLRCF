 /* bo5-51.c ���������д��ʽ��ΪSString���� */
 #include"c4-1.h" /* ����SString���� */
 #include"bo4-1.c" /* SString���͵Ļ������� */
 void sever(SString str,SString hstr) /* �㷨5.8  SString�����飬������������ */
 { /* ���ǿմ�str�ָ��������:hsubΪ��һ��','֮ǰ���Ӵ�,strΪ֮����Ӵ� */
   int n,k,i; /* k����δ��Ե������Ÿ��� */
   SString ch,c1,c2,c3;
   n=StrLength(str);
   StrAssign(c1,",");
   StrAssign(c2,"(");
   StrAssign(c3,")");
   SubString(ch,str,1,1);
   for(i=1,k=0;i<=n&&StrCompare(ch,c1)||k!=0;++i)
   { /* ���������ĵ�һ������ */
     SubString(ch,str,i,1);
     if(!StrCompare(ch,c2))
       ++k;
     else if(!StrCompare(ch,c3))
       --k;
   }
   if(i<=n)
   {
     SubString(hstr,str,1,i-2);
     SubString(str,str,i,n-i+1);
   }
   else
   {
     StrCopy(hstr,str);
     ClearString(str);
   }
 }

 Status CreateGList(GList *L,SString S) /* �㷨5.7 */
 { /* ����ͷβ�����洢�ṹ,�ɹ��������д��ʽ��S���������L����emp="()" */
   SString sub,hsub,emp;
   GList p,q;
   StrAssign(emp,"()");
   if(!StrCompare(S,emp))
     *L=NULL; /* �����ձ� */
   else
   {
     *L=(GList)malloc(sizeof(GLNode));
     if(!*L) /* ������� */
       exit(OVERFLOW);
     if(StrLength(S)==1) /* SΪ��ԭ�� */
     {
       (*L)->tag=ATOM;
       (*L)->a.atom=S[1]; /* ������ԭ�ӹ���� */
     }
     else
     {
       (*L)->tag=LIST;
       p=*L;
       SubString(sub,S,2,StrLength(S)-2); /* ��������� */
       do
       { /* �ظ���n���ӱ� */
         sever(sub,hsub); /* ��sub�з������ͷ��hsub */
         CreateGList(&p->a.ptr.hp,hsub);
         q=p;
         if(!StrEmpty(sub)) /* ��β���� */
         {
           p=(GLNode *)malloc(sizeof(GLNode));
           if(!p)
             exit(OVERFLOW);
           p->tag=LIST;
           q->a.ptr.tp=p;
         }
       }while(!StrEmpty(sub));
       q->a.ptr.tp=NULL;
     }
   }
   return OK;
 }
