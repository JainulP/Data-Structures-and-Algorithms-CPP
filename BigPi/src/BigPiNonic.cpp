#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <mpir.h>
#include <stdlib.h>
#include <string.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int MAX_ITERATIONS = 100;
const int PLACES         = 1000000;        // desired decimal places
const int PRECISION      = PLACES + 1;  // +1 for the digit 3 before the decimal

const int BASE       = 10;  // base 10 numbers
const int BIT_COUNT  = 8;   // bits per machine word

const int BLOCK_SIZE = 10;                // print digits in blocks
const int LINE_SIZE  = 100;               // digits to print per line
const int LINE_COUNT = PLACES/LINE_SIZE;  // lines to print
const int GROUP_SIZE = 5;                 // line grouping size

duration<double> total_time_span;
duration<double> total_time_span_cube_root;
/**
 * Compute the cube root of a positive integer.
 * @param x where to store the result.
 * @param a the number whose cube root to compute.
 */
void cube_root(mpf_t& x, const mpf_t a);

//computed the cube of a given number
//@param y is the number whose cube we want to find
//@param y3 is used to store the result
void power3(mpf_t& y3, const mpf_t y);

// Prints the thousand precision decimal number according to the group size, block size and line size given.
//@param pi the number with thousands precision to be printed
void print(const mpf_t& pi);


/**
 * The main.
 */
int main()
{

	high_resolution_clock::time_point t1 , t2;
	t1 = high_resolution_clock::now() ;
//	duration<double> total_time_span;
//	duration<double> total_time_span_cube_root;
    mpf_set_default_prec(BIT_COUNT * PRECISION);  // precision in bits

    mpf_t pi; mpf_init(pi);

    	//declaring constants for  multiple precision
    		mpf_t  one,two, three,nine;
    		mpf_init(one);  mpf_set_str(one,  "1", BASE);
    		mpf_init(two);  mpf_set_str(two,  "2", BASE);
        mpf_init(three); mpf_set_str(three, "3", BASE);
        mpf_init(nine); mpf_set_str(nine, "9", BASE);




    mpf_t a0,r0,s0;//initial terms for nonic convergence
    mpf_init(a0);mpf_init(r0);mpf_init(s0);

    mpf_t sqrt3, sqrt3_1;
    mpf_init(sqrt3);  mpf_init(sqrt3_1);

    mpf_div(a0, one,three);//a0 = 1/3;

    mpf_sqrt(sqrt3,three);
    mpf_sub(sqrt3_1, sqrt3, one);

    mpf_div(r0, sqrt3_1, two);//computing r0 = ((3^(1/2))-1)/2;

    mpf_t r0cube;  mpf_init(r0cube);
    power3(r0cube,r0);// cube of r0

    mpf_t r0cube_1; mpf_init(r0cube_1);
    mpf_sub(r0cube_1, one, r0cube);

    cube_root(s0,r0cube_1);//s0 = (1 - cube of r0)^(1/3)

    mpf_t t,u,v,w,prev_a,a, s,  r;
    mpf_init(t);mpf_init(u);mpf_init(v);mpf_init(w);
    mpf_init(prev_a);mpf_init(a);mpf_init(s);mpf_init(r);


    //temp variables for computations
    mpf_t temp1,temp2,temp3,temp4,temp5,temp6;
    mpf_init(temp1);mpf_init(temp2);mpf_init(temp3);mpf_init(temp4);mpf_init(temp5);mpf_init(temp6);

    mpf_t power3_2n_1;  mpf_init(power3_2n_1);

    mpf_t one_third; mpf_init(one_third);

    mpf_div(one_third, one, three);

    mpf_set(power3_2n_1, one_third);



    mpf_set(r, r0);
    mpf_set(a, a0);
    mpf_set(s,s0);


int n=0;
    //start iteration
do
{


	 mpf_set(prev_a, a);
	 mpf_div(temp1, one, prev_a);

    //computing t n+1
			mpf_mul(temp1,r,two);//2r
			mpf_add(t,one,temp1);//computing t= 1+2r


			//computing u n+1
			mpf_pow_ui(temp1, r,2);//r square
			mpf_add(temp2, temp1,r);//1+ r
			mpf_add(temp3, temp2,one);//1+ r+ r^2
			mpf_mul(temp4, temp3, r);//r(1+ r+ r^2)
			mpf_mul(temp5,temp4,nine);//9r(1+ r+ r^2)
			cube_root(u,temp5);




			//computing v n+1
			mpf_pow_ui(temp1, t, 2);//t^2
			mpf_pow_ui(temp2, u, 2);//u^2
			mpf_mul(temp3, t,u);//tu
			mpf_add(temp4,temp1,temp2);//t^2 + u^2
			mpf_add(v,temp4,temp3);// v= t^2 + tu+ u^2



			//computing w n+1
			mpf_pow_ui(temp1, s, 2);//s^2
			mpf_add(temp2, temp1, s);//s+ s^2
			mpf_add(temp3, temp2, one);//1+ s+ s^2
			mpf_mul_ui(temp4,temp3,27);//27(1+ s+ s^2)
			mpf_div(w, temp4, v);//27(1+ s+ s^2) / v



			//computing a n+1
			mpf_mul(temp1, w, a);//wa
			mpf_sub(temp2, one, w);//1 -w
			//mpf_mul(power3_2n_1, power3_2n_1, nine);
			mpf_mul(temp3, temp2, power3_2n_1);//(3^(2n-1))(1 - w)
			mpf_add(a, temp1,temp3);//a = wa + (3^(2n-1))(1 - w)




			//computing s n+1
			mpf_sub(temp1, one, r);//1-r
			mpf_pow_ui(temp2, temp1, 3);//(1-r)^3
			mpf_mul(temp3,u,two);//2u
			mpf_add(temp4, temp3, t);//t+2u
			mpf_mul(temp5, temp4,v);//(t+2u)v
			mpf_div(s, temp2, temp5);//s= ((1-r)^3) / ((t+2u)v)



			//computing r n+1
			mpf_pow_ui(temp1, s,3);//s^3
			mpf_sub(temp2,one,temp1);//1 - s^3
			cube_root(r, temp2);


			mpf_mul(power3_2n_1, power3_2n_1, nine);

n++;
	t2 = high_resolution_clock::now() ;
	duration<double> time_span = duration_cast< duration<double> > (t2 - t1);
	cout << endl<< "Elapsed time for iteration number "<< n<<" is: " << time_span.count() << " seconds.";
	t1 = t2;
	total_time_span += time_span;
    }while( ((n<2)|| (mpf_eq(a,prev_a, PRECISION) ==0)) && (n < MAX_ITERATIONS));//iterate till last two values are not equal or n reaches the max number of iterations defined

cout << endl<< "Total Elapsed time is: " << total_time_span.count() << " seconds.";
cout << endl<< "Total Elapsed time for cube root is: " << total_time_span_cube_root.count() << " seconds.";
cout<< endl<< "Percentage of time spent computing cube root is : "<< ((100 *total_time_span_cube_root)/ total_time_span) << " %";

//inverting number a to get the value of pi
mpf_div(pi, one, a);
 print(pi);


    return 0;
}

void power3(mpf_t& y3, const mpf_t y)
{
		mpf_t y2;
	    mpf_init(y2);

	    mpf_mul(y2, y, y);
	    mpf_mul(y3, y2, y);
}

void cube_root(mpf_t& x, const mpf_t a)
{

	high_resolution_clock::time_point t1 , t2;

	 t1 = high_resolution_clock::now() ;
	int n = 0;// iteration counter

	mpf_t xn, xcube,xcube2,
		  two,three,
		  a2,
		  temp1,temp2,temp3;
			mpf_init(xn);mpf_init(xcube);mpf_init(xcube2);mpf_init(a2);mpf_init(temp1);mpf_init(temp2);mpf_init(temp3);
	//mpf_set_str(x,  "1", BASE);

    mpf_t aby3; mpf_init(aby3);
	mpf_init(two); mpf_set_str(two, "2", BASE);
    mpf_init(three); mpf_set_str(three, "3", BASE);

    mpf_div(aby3, a,three);
    mpf_set(xn,aby3);

	do
	{

		mpf_set(x,xn);
		power3(xcube,x);//computing cube of number x

		mpf_mul(xcube2, xcube, two);// multiplying x^3 with 2
		mpf_mul(a2,a,two);// multiplying a with 2
		mpf_add(temp1, xcube,a2);// xn^3 + 2*a
		mpf_add(temp2, xcube2,a);// 2*xn^3 + a
		mpf_div(temp3,temp1,temp2);// dividing (xn^3 + 2*a) by (2*xn^3 + a)
		mpf_mul(xn,x,temp3);//  multiplying xn with ((xn^3 + 2*a) / (2*xn^3 + a))

		n++;




	}while((mpf_cmp(x,xn) !=0) && (n < MAX_ITERATIONS));
	t2 = high_resolution_clock::now() ;
	duration<double> time_span = duration_cast< duration<double> > (t2 - t1);
	 total_time_span_cube_root += time_span;
	//cout << endl<< "Elapsed time in cube root for each iteration is: " << time_span.count() << " seconds.";

}


void print(const mpf_t& pi)
{
    mp_exp_t exponant;


    char* str = mpf_get_str(NULL, &exponant, BASE, PRECISION, pi);
    char *p = str+1;

    cout << endl;
    cout << "3.";

    char block[BLOCK_SIZE + 1];  //for \0 ending size is 1 more

    for (int line = 1; line <= LINE_COUNT; line++)
    {

        for (int size = 0; size < LINE_SIZE; size += BLOCK_SIZE)
        {
            strncpy(block, p+size, BLOCK_SIZE);
            block[BLOCK_SIZE] = '\0';
            cout << block << " ";
        }

        cout << endl << "  ";

        // Print a blank line for grouping.
        if (line == GROUP_SIZE)
        	{
        		cout << endl << "  ";
        	}

        p += LINE_SIZE;
    }

}
