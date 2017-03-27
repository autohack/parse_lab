// © 2017 All Rights Reserved
// Group Number: 12
// Group Member_1: Chetna Warkade
// Group Member_2: Rahul Kant
// Group Member_3: Subham Gupta
// Group Member_4: Sidhharth Khabia

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// global varibles 
const char *keyword[61] = {"add","all","as","alter","and","any","asc","avg","by","char","character" ,"column",
"create","cascade","constraints","date","distinct","double","default","delete","desc","drop","exists","foreign",
"float","from","group","having","in","index","insert","into","is","int","integer","join","key","left","like",
"max","min","not","null","or","order","outer","references","right","schema","select","set","smallint","sum",
"table","union","unique","update","value","values","varchar","where"};

const char *operator[11] = {"*","+","-","/",".","=","<",">","<>",">=","<="};

// structure
struct node
{
    char *name;
    int csize;
    struct node *next[100];
        
};


char error[400];
char *p[100];
int parse_point;
// function declaration
int start();

int line();
int line1();
int line2();
int line3();
int line4();
int line5();
int line6();
int line7();
int line8();
int line9();
int line10();

int sline();
int sline1();
int sline2();
int sline3();
int sline4();

int ao();
int com();
int num();
int using();
int condition();
int new_condition();
int pro_condition();
int new_line();
int nes2();

int t_token();
int id();
int items();
int new_items();
int alpha_items();
int new_alpha_items();
int hyper_items();
int create_items();
int new_hyper_items();
int p_create_items();
int up_cond();
int new_up_cond();
int pp();
int isind();
int iskeyword();
int isval();
char *p1,*p2,*p3,*s;

//---------------------------parse tree printing in sentnetial form funtions start------------------------------//
// int indd = 0;
// printer function: prints the final sentnetial form


int strf(char **p1,char **p2)
{
	int i,j,ret=-1;
	for(i=0;i<strlen(*p2);i++)
	{
		if((*p2)[i]==(*p1)[0])
		{
			ret = i;
			for(j=0;j<strlen(*p1);j++)
			{
				if((*p1)[j]!=(*p2)[j+i])
				{
					ret=-1;
					break;
				}
			}
			if(ret==i)
			{
				return ret;
			}
		}
	}
	return -1;
}
// srp function for sentnetial form
void srp(char **p1,char **p2,char **p3)
{
	int n =strlen(*p2)-strlen(*p1)+strlen(*p3)+1;
		// printf("%d\n",n );

	int ind = strf(p1,p2);
		// printf("%d\n",ind);

	char ret[n];
	int i;
	// printf("1\n");
	for(i=0;i<n-1;i++)
	{
		if(i<ind)
		{
			ret[i]=(*p2)[i];	
		}
		else if(i<ind + strlen(*p3))
		{
			ret[i]=(*p3)[i-ind];
		}
		else
		{
			ret[i] = (*p2)[i-strlen(*p3)+strlen(*p1)];
		}

	}
	ret[n-1]='\0';
	//write  code here
	s = (char *)malloc(n*sizeof(char));
	int l;
	for(l=0;l<n;l++)
	{
		s[l]=ret[l];
	}
	(*p2) = s;
	printf("%s\n",*p2 );
	return;
	
}

// for printing tree
void printer (struct node **n)
{
	
    if((*n)->csize==0)
    {
        return;
    }   
    else
    {
        // printf("innnn\n");
        // printf("%d\n",(*n)->csize );
        printf("Production :%s ->",(*n)->name);
        p1 = (*n)->name;
        
        int i;
        int indd=0;
        char sss[500];
        for(i=0;i<(*n)->csize;i++)				// for that stage
        {
        	int k;

        	for(k=0;k<strlen((*n)->next[i]->name);k++)
        	{
        		sss[k+indd]=((*n)->next[i]->name)[k];
        	}
        	indd+= strlen((*n)->next[i]->name);
        	sss[indd]=' ';
        	indd++;
        	printf("%s ",(*n)->next[i]->name);

        }
        printf("\n");
       	sss[indd-1]='\0';
       	// printf("p1 is :%s\n",p1 );
        // printf("ye hamne banai h :%s\n",sss);
        printf("%s-> ",p2 );
        p3 = sss;
        srp(&p1,&p2,&p3);

        for(i=0;i<(*n)->csize;i++)
        {
            printer(&((*n)->next[i]));		// recursive childs
        }
    }
}
//---------------------------parse tree printing in sentnetial form funtions end------------------------------//
//-------------------------------------------------------------------------------------------------------------//
//----------------------parser funtions start----------------------------------//

// start function : start 

// start state

// start: 			line  | sline | line start | sline start;	

int start(struct node **n)
{
	int s_point = parse_point;
    struct node *no = NULL , *n2=NULL;
    // goes to line 
    if(line(&no))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "start";
        (*n)->next[0] = no;
        (*n)->csize = 1;
        return 1;
    }
    parse_point = s_point;
    // goes to sline
    if(sline(&n2))
    {
    	*n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "start";
        (*n)->next[0] = n2;
        (*n)->csize = 1;
        return 1;
    }
    parse_point = s_point;
    return 0;

}

// line function
int line(struct node **n)
{
	// storing pointer for backward
    int l_point = parse_point;
    struct node *line1p, *line2p, *line3p, *line4p, *line5p, *line6p, *line7p, *line8p, *line9p, *line10p;
    // 10 particular productions emanating from line
    // line 1
    if(line1(&line1p)==1)
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "line";
        (*n)->next[0] = line1p;
        (*n)->csize = 1;
        return 1;
    }

    parse_point = l_point;
    // line 2
    if(line2(&line2p)==1)
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "line";
        (*n)->next[0] = line2p;
        (*n)->csize = 1;
        return 1;
    }


    parse_point = l_point;
    // line 3
    if(line3(&line3p)==1)
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "line";
        (*n)->next[0] = line3p;
        (*n)->csize = 1;
        return 1;
    }

    parse_point = l_point;
    // line 4
    if(line4(&line4p)==1)
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "line";
        (*n)->next[0] = line4p;
        (*n)->csize = 1;
        return 1;
    }

    parse_point = l_point;
    // line 5
    if(line5(&line5p)==1)
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "line";
        (*n)->next[0] = line5p;
        (*n)->csize = 1;
        return 1;
    }

    parse_point = l_point;
    // line 6
    if(line6(&line6p)==1)
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "line";
        (*n)->next[0] = line6p;
        (*n)->csize = 1;
        return 1;
    }

    parse_point = l_point;
    // line 7
    if(line7(&line7p)==1)
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "line";
        (*n)->next[0] = line7p;
        (*n)->csize = 1;
        return 1;
    }

    parse_point = l_point;
    // line 8
    if(line8(&line8p)==1)
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "line";
        (*n)->next[0] = line8p;
        (*n)->csize = 1;
        return 1;
    }

    parse_point = l_point;
    // line 9
    if(line9(&line9p)==1)
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "line";
        (*n)->next[0] = line9p;
        (*n)->csize = 1;
        return 1;
    }

    parse_point = l_point;
    // line 10
    if(line10(&line10p)==1)
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "line";
        (*n)->next[0] = line10p;
        (*n)->csize = 1;
        return 1;
    }

    parse_point = l_point;
    return 0;
}

// sline function
int sline(struct node **n)
{
	int sl_point = parse_point;
	struct node *sline1p, *sline2p, *sline3p, *sline4p;
    // 4 productions emanating from sline function
    // sline 1
	if(sline1(&sline1p)==1)
	{
		*n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "sline";
        (*n)->next[0] = sline1p;
        (*n)->csize = 1;
        return 1;
	}

	parse_point = sl_point;
    // sline 2
	if(sline2(&sline2p)==1)
	{
		*n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "sline";
        (*n)->next[0] = sline2p;
        (*n)->csize = 1;
        return 1;
	}

	parse_point = sl_point;
    // sline 3
	if(sline3(&sline3p)==1)
	{
		*n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "sline";
        (*n)->next[0] = sline3p;
        (*n)->csize = 1;
        return 1;
	}

	parse_point = sl_point;
    // sline 4
	if(sline4(&sline4p)==1)
	{
		*n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "sline";
        (*n)->next[0] = sline4p;
        (*n)->csize = 1;
        return 1;
	}

	parse_point = sl_point;
	return 0;
}

// sline 1 production
// SELECT items FROM IDENTIFIER semi
int sline1(struct node **n)
{
	struct node *selectp, *itemsp, *fromp, *idp, *colp;
	if(t_token("select",&selectp) && items(&itemsp) && t_token("from",&fromp) && id(&idp) && t_token(";",&colp))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "sline1";
        (*n)->next[0] = selectp;
        (*n)->next[1] = itemsp;
        (*n)->next[2] = fromp;
        (*n)->next[3] = idp;
        (*n)->next[4] = colp;
        (*n)->csize = 5;
        return 1;
    }
    return 0;
}

// sline 2 production 
// SELECT items using pro_condition semi
int sline2(struct node **n)
{
	struct node *selectp, *itemsp, *usingp, *pro_condp, *colp;
	if(t_token("select",&selectp) && items(&itemsp) && using(&usingp) && pro_condition(&pro_condp) && t_token(";",&colp))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "sline2";
        (*n)->next[0] = selectp;
        (*n)->next[1] = itemsp;
        (*n)->next[2] = usingp;
        (*n)->next[3] = pro_condp;
        (*n)->next[4] = colp;
        (*n)->csize = 5;
        return 1;
    }
    return 0;
}

// sline 3
// SELECT '*' FROM IDENTIFIER semi 
int sline3(struct node **n)
{
	struct node *selectp, *starp, *fromp, *idp, *colp;
	if(t_token("select",&selectp) && t_token("*", &starp) && t_token("from", &fromp) && id(&idp) && t_token(";",&colp))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "sline3";
        (*n)->next[0] = selectp;
        (*n)->next[1] = starp;
        (*n)->next[2] = fromp;
        (*n)->next[3] = idp;
        (*n)->next[4] = colp;
        (*n)->csize = 5;
        return 1;
    }
    return 0;
}

// sline 4
// SELECT '*' using pro_condition semi
int sline4(struct node **n)
{
	struct node *selectp, *starp, *usingp, *pro_conditionp, *colp;
	if(t_token("select",&selectp) && t_token("*", &starp) && using(&usingp) && pro_condition(&pro_conditionp) && t_token(";",&colp))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "sline4";
        (*n)->next[0] = selectp;
        (*n)->next[1] = starp;
        (*n)->next[2] = usingp;
        (*n)->next[3] = pro_conditionp;
        (*n)->next[4] = colp;
        (*n)->csize = 5;
        return 1;
    }
    return 0;
}

// 10 line functions for representing productions emanating from line
// line:           DELETE FROM IDENTIFIER semi
int line1(struct node **n)
{
    struct node *deletep,*fromp,*idp,*colp;
    if(t_token("delete",&deletep) && t_token("from",&fromp) && id(&idp) && t_token(";",&colp))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "line1";
        (*n)->next[0] = deletep;
        (*n)->next[1] = fromp;
        (*n)->next[2] = idp;
        (*n)->next[3] = colp;
        (*n)->csize = 4;
        return 1;
    }
    return 0;
}

// line:           DELETE FROM identifier WHERE
int line2(struct node **n)
{
    struct node *deletep,*idp, *fromp, *wherep, *conditionp,*colp;
    if(t_token("delete",&deletep)&& t_token("from", &fromp) && id(&idp) && t_token("where", &wherep) && condition(&conditionp) && t_token(";",&colp))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "line2";
        (*n)->next[0] = deletep;
        (*n)->next[1] = fromp;
        (*n)->next[2] = idp;
        (*n)->next[3] = wherep;
        (*n)->next[4] = conditionp;
        (*n)->next[5] = colp;
        (*n)->csize = 6;
        return 1;
    }
    return 0;
}

// line:              DROP TABLE IDENTIFIER semi
int line3(struct node **n)
{
    struct node *dropp,*tablep,*idp,*colp;
    if(t_token("drop",&dropp) && t_token("table",&tablep) && id(&idp) && t_token(";",&colp))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "line3";
        (*n)->next[0] = dropp;
        (*n)->next[1] = tablep;
        (*n)->next[2] = idp;
        (*n)->next[3] = colp;
        (*n)->csize = 4;
        return 1;
    }
    return 0;
}

// line:               ALTER TABLE IDENTIFIER DROP COLUMN items semi
int line4(struct node **n)
{
    struct node  *alterp,*dropp,*tablep,*columnp,*itemp,*idp,*colp;
    if(t_token("alter" , &alterp)&& t_token("table", &tablep)&& id(&idp)&&t_token("drop",&dropp) && t_token("column" , &columnp) && items(&itemp) && t_token(";",&colp))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "line4";
        (*n)->next[0] = alterp;
        (*n)->next[1] = tablep;
        (*n)->next[2] = idp;
        (*n)->next[3] = dropp;
        (*n)->next[4] = columnp;
        (*n)->next[5] = itemp;
        (*n)->next[6] = colp;
        (*n)->csize = 7;
        return 1;
    }
    return 0;
}

// line:               ALTER TABLE IDENTIFIER ADD IDENTIFIER IDENTIFIER semi
int line5(struct node **n)
{
    struct node  *alterp,*tablep, *addp , *id1p, *id2p, *id3p, *colp;
    if(t_token("alter" , &alterp)&& t_token("table", &tablep)&& id(&id1p) && t_token("add", &addp) && id(&id2p)&& id(&id3p)&& t_token(";",&colp))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "line5";
        (*n)->next[0] = alterp;
        (*n)->next[1] = tablep;
        (*n)->next[2] = id1p;
        (*n)->next[3] = addp;
        (*n)->next[4] = id2p;
        (*n)->next[5] = id3p;
        (*n)->next[6] = colp;
        (*n)->csize = 7;
        return 1;
    }
    return 0;
}

// line:                   INSERT INTO IDENTIFIER VALUES leftbr alpha_items rightbr semi
int line6(struct node **n)
{
    struct node  *insertp, *intop, *valuesp, *leftbrp, *alpha_itemsp, *rightbrp, *colp , *idp;
    if(t_token("insert", &insertp) && t_token("into", &intop) && id(&idp)&& t_token("values", &valuesp) && t_token("(", &leftbrp) && alpha_items(&alpha_itemsp) && t_token(")", &rightbrp) && t_token(";",&colp))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "line5";
        (*n)->next[0] = insertp;
        (*n)->next[1] = intop;
        (*n)->next[2] = idp;
        (*n)->next[3] = valuesp;
        (*n)->next[4] = leftbrp;
        (*n)->next[5] = alpha_itemsp;
        (*n)->next[6] = rightbrp;
        (*n)->next[7] = colp;
        (*n)->csize = 8;
        return 1;
    }
    return 0;
}

// line:                   INSERT INTO IDENTIFIER leftbr items rightbr VALUES leftbr alpha_items rightbr semi
int line7(struct node **n)
{
    struct node *insertp, *intop, *idp, *itemsp, *valuesp, *leftbr1p, *rightbr1p, *alpha_itemsp, *leftbr2p, *rightbr2p, *colp;
    if(t_token("insert", &insertp) && t_token("into", &intop) && id(&idp)&& t_token("(",&leftbr1p) && items(&itemsp) && t_token(")", &rightbr1p) && t_token("values", &valuesp) && t_token("(", &leftbr2p) && alpha_items(&alpha_itemsp) && t_token(")", &rightbr2p) && t_token(";",&colp))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "line7";
        (*n)->next[0] = insertp;
        (*n)->next[1] = intop;
        (*n)->next[2] = idp;
        (*n)->next[3] = leftbr1p;
        (*n)->next[4] = itemsp;
        (*n)->next[5] = rightbr1p;
        (*n)->next[6] = valuesp;
        (*n)->next[7] = leftbr2p;
        (*n)->next[8] = alpha_itemsp;
        (*n)->next[9] = rightbr2p;
        (*n)->next[10] = colp;
        (*n)->csize = 11;
        return 1;
    }
    return 0;
}

// line:                   CREATE TABLE IDENTIFIER leftbr hyper_items rightbr semi
int line8(struct node **n)
{
    struct node *createp, *tablep,*idp, *leftbrp, *hyper_itemsp, *rightbrp, *colp;
    if(t_token("create", &createp) && t_token("table", &tablep) && id(&idp)&& t_token("(",&leftbrp) && hyper_items(&hyper_itemsp) && t_token(")", &rightbrp) && t_token(";",&colp))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "line8";
        (*n)->next[0] = createp;
        (*n)->next[1] = tablep;
        (*n)->next[2] = idp;
        (*n)->next[3] = leftbrp;
        (*n)->next[4] = hyper_itemsp;
        (*n)->next[5] = rightbrp;
        (*n)->next[6] = colp;
        (*n)->csize = 7;
        return 1;
    }
    return 0;
}

// line:                   UPDATE IDENTIFIER SET up_cond semi
int line9(struct node **n)
{
    struct node *updatep, *idp, *setp, *up_condp, *colp;
    if(t_token("update", &updatep) && id(&idp)&& t_token("set",&setp) && up_cond(&up_condp) && t_token(";",&colp))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "line9";
        (*n)->next[0] = updatep;
        (*n)->next[1] = idp;
        (*n)->next[2] = setp;
        (*n)->next[3] = up_condp;
        (*n)->next[4] = colp;
        (*n)->csize = 5;
        return 1;
    }
    return 0;
}

// line:                   UPDATE IDENTIFIER SET up_cond WHERE pro_condition semi
int line10(struct node **n)
{
    struct node *updatep, *idp, *setp, *up_condp, *wherep, *pro_condp, *colp;
    if(t_token("update", &updatep) && id(&idp)&& t_token("set",&setp) && up_cond(&up_condp) && t_token("where", &wherep) && pro_condition(&pro_condp) && t_token(";",&colp))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "line10";
        (*n)->next[0] = updatep;
        (*n)->next[1] = idp;
        (*n)->next[2] = setp;
        (*n)->next[3] = up_condp;
        (*n)->next[4] = wherep;
        (*n)->next[5] = pro_condp;
        (*n)->next[6] = colp;
        (*n)->csize = 7;
        return 1;
    }
    return 0;
}


// productions for conditions 
// pro_condition:  nes_condition | condition ;
int pro_condition(struct node **n)
{
	int pc_point = parse_point;
	struct node *idp ,*comp, *leftbrp , *new_linep , *rightbrp , *conditionp;

	if(id(&idp)&&com(&comp)&&t_token("(",&leftbrp) && new_line(&new_linep) && t_token(")" , &rightbrp))
	{
		*n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "pro_condition";
        (*n)->next[0] = idp;
        (*n)->next[1] = comp;
        (*n)->next[2] = leftbrp;
        (*n)->next[3] = new_linep;
        (*n)->next[4] = rightbrp;
        (*n)->csize = 5;
        return 1;
	}

	parse_point = pc_point;
	if(condition(&conditionp))
	{
		*n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "pro_condition";
        (*n)->next[0] = conditionp;
        (*n)->csize = 1;
		return 1;
	}

	parse_point = pc_point;
	return 0;
}

// up_cond:        IDENTIFIER '=' IDENTIFIER new_up_cond | IDENTIFIER '=' NUMBER new_up_cond;
int up_cond(struct node **n)
{
    struct node *id1p , *eqp , *id2p , *new_up_condp , *nump;
    int up_point = parse_point;
    if(id(&id1p)&&t_token("=",&eqp) && id(&id2p) && new_up_cond(&new_up_condp))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "up_cond";
        (*n)->next[0] = id1p;
        (*n)->next[1] = eqp;
        (*n)->next[2] = id2p;
        (*n)->next[3] = new_up_condp;

        (*n)->csize = 4;
        return 1;
    }

    parse_point = up_point;
    if(id(&id1p)&&t_token("=", &eqp) && num(&nump) && new_up_cond(&new_up_condp))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "up_cond";
        (*n)->next[0] = id1p;
        (*n)->next[1] = eqp;
        (*n)->next[2] = nump;
        (*n)->next[3] = new_up_condp;

        (*n)->csize = 4;

        return 1;
    }

    parse_point = up_point;
    return 0;
}

// new_up_cond:    ',' IDENTIFIER '=' IDENTIFIER new_up_cond | ',' IDENTIFIER '=' NUMBER new_up_cond | ;
int new_up_cond(struct node **n)
{
    int nup_point = parse_point;
    struct node *commap , *id1p , *eqp , *id2p , *new_up_condp, *nump;
    if(t_token(",", &commap)&& id(&id1p)&&t_token("=",eqp) && id(&id2p) && new_up_cond(&new_up_condp))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "new_up_cond";
        (*n)->next[0] = commap;
        (*n)->next[1] = id1p;
        (*n)->next[2] = eqp;
        (*n)->next[3] = id2p;
        (*n)->next[4] = new_up_condp;
        (*n)->csize = 5;
        return 1;

    }

    parse_point = nup_point;
    if( t_token(",",&commap)&& id(&id1p)&&t_token("=",eqp) && num(&nump) && new_up_cond(&new_up_condp))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "new_up_cond";
        (*n)->next[0] = commap;
        (*n)->next[1] = id1p;
        (*n)->next[2] = eqp;
        (*n)->next[3] = nump;
        (*n)->next[4] = new_up_condp;
        (*n)->csize = 5;
        return 1;

    }

    // special epislon case
    parse_point = nup_point;
    struct node *idd;
    idd =  (struct node *)malloc(sizeof(struct node));
    idd->name = "";
    idd->csize = 0;
    *n =  (struct node *)malloc(sizeof(struct node));
    (*n)->name = "new_up_cond";
    (*n)->next[0] = idd;
    (*n)->csize = 1;
    return 1;
}


// new_line:       SELECT items using pro_condition| SELECT items FROM IDENTIFIER 
// new_line:       SELECT '*' FROM IDENTIFIER | SELECT '*' using pro_condition ;

// for nested queries

int new_line(struct node **n)
{
	int nl_point = parse_point;
	struct node *selectp , *itemsp, *pro_conditionp , *fromp , *idp , *usingp , *starp;
	if(t_token("select" , &selectp) && items(&itemsp) && using(&usingp) && pro_condition(&pro_conditionp))
	{
		*n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "new_line";
        (*n)->next[0] = selectp;
        (*n)->next[1] = itemsp;
        (*n)->next[2] = usingp;
        (*n)->next[3] = pro_conditionp;
        (*n)->csize = 4;
		return 1;
	}

	parse_point = nl_point;
	if(t_token("select",&selectp) && items(&itemsp) && t_token("from",&fromp) && id(&idp))
	{
		*n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "new_line";
        (*n)->next[0] = selectp;
        (*n)->next[1] = itemsp;
        (*n)->next[2] = fromp;
        (*n)->next[3] = idp;
        (*n)->csize = 4;
		return 1;
	}

	parse_point = nl_point;
	if(t_token("select",&selectp) && t_token("*",&starp) && t_token("from",&fromp) && id(&idp))
	{
		*n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "new_line";
        (*n)->next[0] = selectp;
        (*n)->next[1] = starp;
        (*n)->next[2] = fromp;
        (*n)->next[3] = idp;
        (*n)->csize = 4;
		return 1;
	}

	parse_point = nl_point;
	if(t_token("select",&selectp) && t_token("*" , &starp) && using(&usingp) && pro_condition(&pro_conditionp))
	{
		*n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "new_line";
        (*n)->next[0] = selectp;
        (*n)->next[1] = starp;
        (*n)->next[2] = usingp;
        (*n)->next[3] = pro_conditionp;
        (*n)->csize = 4;
		return 1;
	}

	parse_point = nl_point;
	return 0;
}

// using:          FROM nes2 WHERE;
int using(struct node **n)
{
    struct node *from,*nes2p,*where;
    if(t_token("from",&from) && nes2(&nes2p) && t_token("where",&where))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "using";
        (*n)->next[0] = from;
        (*n)->next[1] = nes2p;
        (*n)->next[2] = where;
        (*n)->csize = 3;
        return 1;
    }
    return 0;
}

// condition:      IDENTIFIER comparator IDENTIFIER new_condition | IDENTIFIER comparator NUMBER new_condition;
int condition(struct node **n)
{
    struct node *idp,*comp,*new_conditionp,*nump;
    int c_point = parse_point;

    if(id(&idp) && com(&comp) && id(&idp) && new_condition(&new_conditionp))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "condition";
        (*n)->next[0] = idp;
        (*n)->next[1] = comp;
        (*n)->next[2] = idp;
        (*n)->next[3] = new_conditionp;
        (*n)->csize = 4;
        return 1;
    }

    parse_point = c_point;
    if(id(&idp) && com(&comp) && num(&nump) && new_condition(&new_conditionp))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "condition";
        (*n)->next[0] = idp;
        (*n)->next[1] = comp;
        (*n)->next[2] = nump;
        (*n)->next[3] = new_conditionp;
        (*n)->csize = 4;
        return 1;
    }

    parse_point = c_point;
    return 0;
}

// nes2:           Identifier | (new_line) | ';'
int nes2(struct node **n)
{
    struct node *idp , *leftbrp,*rightbrp,*new_linep;
    int nc_point = parse_point;
    if(id(&idp))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "nes2";
        (*n)->next[0] = idp;
        (*n)->csize = 1;
        return 1;
    }   
        

    parse_point = nc_point;

    if(t_token("(", &leftbrp) && new_line(&new_linep) && t_token(")", &rightbrp))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "nes2";
        (*n)->next[0] = leftbrp;
        (*n)->next[1] = new_linep;
        (*n)->next[2] = rightbrp;
        (*n)->csize = 3;
        return 1;
    }   

    // epsilon case 
    parse_point = nc_point;
    struct node *idd;
    idd =  (struct node *)malloc(sizeof(struct node));
    idd->name = "";
    idd->csize = 0;
    *n =  (struct node *)malloc(sizeof(struct node));
    (*n)->name = "nes2";
    (*n)->next[0] = idd;
    (*n)->csize = 1;

    return 1;
}

// new_condition:  ao IDENTIFIER comparator IDENTIFIER new_condition | ao IDENTIFIER comparator NUMBER new_condition | ;
int new_condition(struct node **n)
{
    struct node *aop , *idp , *comp , *nump , *new_conditionp;
    int nc_point = parse_point;
    if(ao(&aop)&& id(&idp) && com(&comp) && id(&idp) && new_condition(&new_conditionp))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "new_condition";
        (*n)->next[0] = aop;
        (*n)->next[1] = idp;
        (*n)->next[2] = comp;
        (*n)->next[3] = idp;
        (*n)->next[4] = new_conditionp;
        (*n)->csize = 5;
        return 1;
    }   
        

    parse_point = nc_point;

    if(ao(&aop)&& id(&idp) && com(&comp) && num(&nump) && new_condition(&new_conditionp))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "new_condition";
        (*n)->next[0] = aop;
        (*n)->next[1] = idp;
        (*n)->next[2] = comp;
        (*n)->next[3] = nump;
        (*n)->next[4] = new_conditionp;
        (*n)->csize = 5;
        return 1;
    }   

     // epsilon case 
    parse_point = nc_point;
    struct node *idd;
    idd =  (struct node *)malloc(sizeof(struct node));
    idd->name = "";
    idd->csize = 0;
    *n =  (struct node *)malloc(sizeof(struct node));
    (*n)->name = "new_condition";
    (*n)->next[0] = idd;
    (*n)->csize = 1;

    return 1;
}

// productions representing items
// hyper_items:    create_items  new_hyper_items;
int hyper_items(struct node **n)
{
	struct node *create_itemsp, *new_hyper_itemsp;
	if(create_items(&create_itemsp) && new_hyper_items(&new_hyper_itemsp))
	{
		*n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "hyper_items";
        (*n)->next[0] = create_itemsp;
        (*n)->next[1] = new_hyper_itemsp;
        (*n)->csize = 2;
        return 1;
	}
	return 0;
}

// new_hyper_items:  ',' create_items new_hyper_items| ;
int new_hyper_items(struct node **n)
{
	struct node *commap , *create_itemsp , *new_hyper_itemsp;
	int nhi_point = parse_point;
	if(t_token(",", &commap) &&create_items(&create_itemsp) && new_hyper_items(&new_hyper_itemsp))
	{
		*n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "new_hyper_items";
        (*n)->next[0] = commap;
        (*n)->next[1] = create_itemsp;
        (*n)->next[2] = new_hyper_itemsp;
        (*n)->csize = 3;
		return 1;
	}

	// epsilon case 
	parse_point = nhi_point;
    struct node *idd;
    idd =  (struct node *)malloc(sizeof(struct node));
    idd->name = "";
    idd->csize = 0;
    *n =  (struct node *)malloc(sizeof(struct node));
    (*n)->name = "new_hyper_items";
    (*n)->next[0] = idd;
    (*n)->csize = 1;
	return 1;
}

// create_items:   IDENTIFIER IDENTIFIER | IDENTIFIER create_items;
int create_items(struct node **n)
{
	struct node *p_create_itemsp , *ppp;
    if(p_create_items(&p_create_itemsp) && pp(&ppp))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "create_items";
        (*n)->next[0] = p_create_itemsp;
        (*n)->next[1] = ppp;
        (*n)->csize = 2;
        return 1;
    }
    return 0;
}

// p_create_items: IDENTIFIER INT | IDENTIFIER CHAR leftbr NUMBER rightbr | IDENTIFIER VARCHAR leftbr NUMBER rightbr;
int p_create_items(struct node **n)
{
	int pci_point = parse_point;
	struct node *idp , *intp , *charp , *varcharp , *leftbrp , *nump , *rightbrp;
	if(id(&idp)&&t_token("int" , &intp))
	{
		*n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "p_create_items";
        (*n)->next[0] = idp;
        (*n)->next[1] = intp;
        (*n)->csize = 2;
        return 1;
		
	}


	parse_point =pci_point;
	if(id(&idp) && t_token("char" , &charp) && t_token("(", &leftbrp) && num(&nump) && t_token(")",&rightbrp))
	{
		*n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "p_create_items";
        (*n)->next[0] = idp;
        (*n)->next[1] = charp;
        (*n)->next[2] = leftbrp;
        (*n)->next[3] = nump;
        (*n)->next[4] = rightbrp;
        (*n)->csize = 5;
        return 1;
		
	}

	parse_point = pci_point;
	if(id(&idp) && t_token("varchar",&varcharp) && t_token("(", &leftbrp) && num(&nump) && t_token(")",&rightbrp))
	{
		*n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "p_create_items";
        (*n)->next[0] = idp;
        (*n)->next[1] = varcharp;
        (*n)->next[2] = leftbrp;
        (*n)->next[3] = nump;
        (*n)->next[4] = rightbrp;
        (*n)->csize = 5;
        return 1;
		
	}

	parse_point = pci_point;
	return 0;


}

// pp:             PRIMARY KEY | ;
int pp(struct node **n)
{
	int pp_point = parse_point;
	struct node *primaryp , *keyp;
	if(t_token("primary",&primaryp) && t_token("key" , &keyp))
	{
		*n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "pp";
        (*n)->next[0] = primaryp;
        (*n)->next[1] = keyp;
        (*n)->csize = 2;
		return 1;
	}

	parse_point = pp_point;
	struct node *idd;
    idd =  (struct node *)malloc(sizeof(struct node));
    idd->name = "";
    idd->csize = 0;
    *n =  (struct node *)malloc(sizeof(struct node));
    (*n)->name = "pp";
    (*n)->next[0] = idd;
    (*n)->csize = 1;
	return 1;
}

// alpha_items:     NUMBER new_alpha_item|  STRING new_alpha_item ;
int alpha_items(struct node **n)
{
    int ai_point = parse_point;
    struct node *nump , *new_alpha_itemsp , *idp ;

    if(num(&nump) && new_alpha_items(&new_alpha_itemsp))
    {

        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "alpha_items";
        (*n)->next[0] = nump;
        (*n)->next[1] = new_alpha_itemsp;
        (*n)->csize = 2;
        return 1;
    }

    // new_alpha_itemsp = NULL;
    parse_point = ai_point;
    if(id(&idp) && new_alpha_items(&new_alpha_itemsp))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "aplha_items";
        (*n)->next[0] = idp;
        (*n)->next[1] = new_alpha_itemsp;
        (*n)->csize = 2;
        return 1;
    }

    parse_point = ai_point;
    return 0;
} 


// new_alpha_item: ',' NUMBER new_alpha_item | ',' STRING new_alpha_item |/*e*/ ;
int new_alpha_items(struct node **n)
{
    int nai_point = parse_point;
    struct node *commap , *new_alpha_itemsp , *nump , *idp;
    if(t_token("," , &commap)  && id(&idp) && new_alpha_items(&new_alpha_itemsp))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "new_alpha_condition";
        (*n)->next[0] = commap;
        (*n)->next[1] = idp;
        (*n)->next[2] = new_alpha_itemsp;
        (*n)->csize = 3;
        return 1;
    }

    parse_point = nai_point;
    if(t_token("," , &commap) && num(&nump)&& new_alpha_items(&new_alpha_itemsp))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "new_alpha_condition";
        (*n)->next[0] = commap;
        (*n)->next[1] = nump;
        (*n)->next[2] = new_alpha_itemsp;
        (*n)->csize = 3;
        return 1;
    }


    parse_point = nai_point;
    struct node *idd;
    idd =  (struct node *)malloc(sizeof(struct node));
    idd->name = "";
    idd->csize = 0;
    *n =  (struct node *)malloc(sizeof(struct node));
    (*n)->name = "new_alpha_items";
    (*n)->next[0] = idd;
    (*n)->csize = 1;
    return 1;
}

// items:          IDENTIFIER new_items;
int items(struct node **n)
{
    struct node *idp , *new_itemsp;
    if(id(&idp) && new_items(&new_itemsp))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "items";
        (*n)->next[0] = idp;
        (*n)->next[1] = new_itemsp;
        (*n)->csize = 2;
        return 1;
    }
    return 0;
}

// new_items:      ',' IDENTIFIER new_items| ;
int new_items(struct node **n)
{
    struct node *commap , *idp , *new_itemsp;
    int ni_point = parse_point;
    if((t_token(",",&commap)  && id(&idp) && new_items(&new_itemsp)))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "new_condition";
        (*n)->next[0] = commap;
        (*n)->next[1] = idp;
        (*n)->next[2] = new_itemsp;
        (*n)->csize = 3;
        return 1;
    }   


    parse_point = ni_point;
    struct node *idd;
    idd =  (struct node *)malloc(sizeof(struct node));
    idd->name = "";
    idd->csize = 0;
    *n =  (struct node *)malloc(sizeof(struct node));
    (*n)->name = "new_items";
    (*n)->next[0] = idd;
    (*n)->csize = 1;
    return 1;

}

// for find numbers
int num(struct node **n)
{
    if(isval(p[parse_point]))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = p[parse_point];
        (*n)->csize = 0;
        parse_point++;
        return 1;
    }
    else
        return 0;
}

// comparator:     '=' | "<=" | '<' | ">=" | '>';
int com(struct node **n)
{
    if(!strcmp(p[parse_point],"=") || !strcmp(p[parse_point],"<=") || !strcmp(p[parse_point],"<") || !strcmp(p[parse_point],">=")|| !strcmp(p[parse_point],">"))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = p[parse_point];
        (*n)->csize = 0;
        parse_point++;
        return 1;
    }
    else
        return 0;
    
}

// ao:             AND | OR ; 
int ao(struct node **n)
{
    if(!strcmp(p[parse_point],"and") || !strcmp(p[parse_point],"or"))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = p[parse_point];
        (*n)->csize = 0;
        parse_point++;
        return 1;
    }
    else
        return 0;
}

// for finding identifiers

int id(struct node **n)
{
    if(isind(p[parse_point]))
    {
        struct node *idd;
        idd =  (struct node *)malloc(sizeof(struct node));
        idd->name = p[parse_point];
        idd->csize = 0;

        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = "id";
        (*n)->csize = 1;
        (*n)->next[0] = idd;
        parse_point++;
        return 1;
    }
    else
        return 0;
}

// token SELECT FROM INT CHAR VARCHAR  PRIMARY KEY STRING IDENTIFIER WHERE AND OR DROP DELETE TABLE ALTER COLUMN ADD CREATE INTO VALUES INSERT UPDATE SET NUMBER
int t_token(char *s,struct node **n)
{
    if(!strcmp(p[parse_point],s))
    {
        *n =  (struct node *)malloc(sizeof(struct node));
        (*n)->name = p[parse_point];
        (*n)->csize = 0;
        parse_point++;
        return 1;
    }
    else
    {
    	strcpy(error,"Error ! Couldn't match ");
    	strcat(error,p[parse_point]);
    
    	strcat(error," with any production rule.\nTry again.");
    	
        return 0;
    }
}
//----------------------parser funtions end-------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------//
//----------------------lex functions start---------------------------------------------------------------------//
// keywords array check
int iskeyword(char *str)
{

    int i;
    for(i = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }
    for(i=0;i<=60;i++)
    {
        if(!strcmp(keyword[i],str))
            return 1;
    }
    return 0;
}

// operator finding fuction 
int isoperator(char *str)
{
    int i;
    for(i=0;i<=10;i++)
    {
        if(!strcmp(operator[i],str))
            return 1;
    }
    return 0;
}

// value check 

int isval(char *str)
{
    int i;
    for (i=0;i<strlen(str);i++){
        if(!isdigit(str[i]))
            return 0;
    }
    return 1;
}
// identifier check

int isind(char *str)
{
	int i,flag = 0;
	if(isalpha(str[0]))
	{
		for(i=1;i<strlen(str);i++)
		{	
			if(!isalnum(str[i]))
			{
				flag = 1;
				return 0;
			}

		}
	}
	else
	{
		flag =1;
	}

	if(flag==0)
		return 1;
	return 0;

}
//-------------------------lex functions end-------------------------------------------------------------------//

//-------------------------------------------------------------------------------------------------------------//

// main function
int main()
{
//-----------start----------------//
    char s[100],c[100];
    
    int i = 0,j=0,k=0,z=0,y=0;
//-----taking input in while loop till exit --------------//
    while(1){
        scanf("%[^'\n']s",s);
        getchar();

        if(!strcmp(s,"exit"))
            break;
//------------tokenize the sring ------------------//
        while(s[z] != '\0')
        {
            if(s[z]=='>' && s[z+1] =='=')
            {
                c[y] = ' ';
                c[++y] = s[z];
                c[++y] = s[++z];
                c[++y] = ' ';

            }
            else if(s[z]=='<' && s[z+1] =='=')
            {
                c[y] = ' ';
                c[++y] = s[z];
                c[++y] = s[++z];
                c[++y] = ' ';

            }
            else if(s[z]=='<' && s[z+1] =='>')
            {
                c[y] = ' ';
                c[++y] = s[z];
                c[++y] = s[++z];
                c[++y] = ' ';

            }
            else if(s[z]=='*' || s[z] ==';' || s[z] == '(' || s[z] == ')' || s[z] ==',' || s[z] == '>' || s[z] == '<' ||
                s[z] == '='|| s[z] == '-' || s[z] == '+' || s[z] == '/' || s[z] == ';')
            {
                c[y] = ' ';
                c[++y] = s[z];
                c[++y] = ' ';
            }
            else
            {
                c[y] = s[z];
            }
            y++;
            z++;
        }
        c[y] = '\0';
        printf("%s\n", c);
        p[0] = strtok(c, " ");
        i = 0;

        while(p[i] != NULL)
        {
            i++;
            p[i] = strtok(NULL," ");
        }
//-------------------------------------------------//
//------------lexical analysis start from here-----------//
        j = 0;

        while(p[j]!= NULL)
        {
            if(iskeyword(p[j]))
            {
                printf("%s\t\t : Keyword\n",p[j] );
            }
            else if (isoperator(p[j]))
            {
                printf("%s\t\t : Operator\n",p[j] );
            }
            else if(!strcmp(p[j],")"))
            {
                printf("%s\t\t : Right Bracket\n",p[j] );
            }
            else if(!strcmp(p[j],"("))
            {
                printf("%s\t\t : Left Bracket\n",p[j] );
            }
            else if(!strcmp(p[j],","))
            {
                printf("%s\t\t : Comma\n",p[j] );
            }
            else if(!strcmp(p[j],";"))
            {
                printf("%s\t\t : Semi Colon\n",p[j] );
            }
            else if(isval(p[j]))
            {
                printf("%s\t\t : Value\n", p[j]);
            }
            else if (isdigit(p[j][0]) && !isdigit(p[j][1]))
            {
                printf("%s\t\t : Invalid Identifier\n",p[j] );
                printf("ERROR: Invalid Identifier. You have an error in your SQL lexeme near '%s.\n",p[j]);
                exit(1);
            }

            
            else if(isind(p[j]))
            {
                printf("%s\t\t : Identifier\n",p[j]);
            }
            else
            {
                printf("%s\t\t : Invalid Token\n",p[j]);
            }
            j++;

        }

        j=0;


//--------------------------------------------------------//
// --------------Lexical analysis ends-------------------//

// -------------Syntactical analysis starts---------------//


        parse_point = 0;
        struct node *no=NULL;

        int success = start(&no);

        if(success==1)
        {
            printf("Success\n");
        	p2 = no->name;
        	// printf("p2 is :%s\n",p2 );
            printer(&no);

        }
        else
        {
        	printf("%s\n", error);
            printf("Failed\n");
        }
// -------------Syntactical analysis ends---------------//
        while(p[k] != NULL)
        {
            p[k] = NULL;
            k++;
        }

        k=0;
        y=0;z=0;
        
    }
    return 0;
}// end main 

// end of the program flow