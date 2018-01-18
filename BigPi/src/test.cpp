//void power3(mpf_t& y3, const mpf_t y)
//{
//		mpf_t y2;
//	    mpf_init(y2);
//
//	    mpf_mul(y2, y, y);
//	    mpf_mul(y3, y2, y);
//}
//
//void cube_root(mpf_t& x, const mpf_t a)
//{
//
//	mpf_t xn, xcube,xcube2,
//		  two,three,
//		  a2,
//		  temp1,temp2,temp3;
//			mpf_init(xn);mpf_init(xcube);mpf_init(xcube2);mpf_init(a2);mpf_init(temp1);mpf_init(temp2);mpf_init(temp3);
//	//mpf_set_str(x,  "1", BASE);
//
//    mpf_t aby3; mpf_init(aby3);
//	mpf_init(two); mpf_set_str(two, "2", BASE);
//    mpf_init(three); mpf_set_str(three, "3", BASE);
//
//    mpf_div(aby3, a,three);
//    mpf_set(xn,aby3);
//
//	do
//	{
//
//		mpf_set(x,xn);
//		power3(xcube,x);//computing cube of number x
//
//		mpf_mul(xcube2, xcube, two);// multiplying x^3 with 2
//		mpf_mul(a2,a,two);// multiplying a with 2
//		mpf_add(temp1, xcube,a2);// xn^3 + 2*a
//		mpf_add(temp2, xcube2,a);// 2*xn^3 + a
//		mpf_div(temp3,temp1,temp2);// dividing (xn^3 + 2*a) by (2*xn^3 + a)
//		mpf_mul(xn,x,temp3);//  multiplying xn with ((xn^3 + 2*a) / (2*xn^3 + a))
//
//
//	}while(mpf_cmp(x,xn));
//
//
//
//
//
//
//
//
//}
