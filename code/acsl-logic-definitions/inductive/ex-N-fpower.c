/*@
  inductive is_power(integer x, integer n, integer r) {
  case zero: \forall integer x ; is_power(x, 0, 1) ;
  case N: \forall integer x, n, r ; n > 0 ==> is_power(x, n-1, r) ==> is_power(x, n, r*x) ;
  }
*/

/*@
  lemma power_mult:
    \forall integer x, y, n, rx, ry ;
    n >= 0 ==> is_power(x, n, rx) ==> is_power(y, n, ry) ==> is_power(x * y, n, rx * ry) ;
    
  lemma power_even:
    \forall integer x, n, r ;
    n >= 0 ==> is_power(x * x, n, r) ==> is_power(x, n * 2, r) ;

  lemma power_odd:
    \forall integer x, n, rp ;
    n >= 0 ==> is_power(x * x, n, rp) ==> is_power(x, 2 * n + 1, x * rp) ; 
*/

/*@
  requires n >= 0 ;
  assigns \nothing ;
  ensures is_power(x, n, \result);
*/
int power(int x, int n){
  int r = 1 ;
  int p = x ;

  /*@
    loop invariant 0 <= n ;
    loop invariant \forall integer v ; is_power(p, n, v) ==> is_power(x, \at(n, Pre), r * v) ;
    loop assigns n, r, p ;
    loop variant n ;
  */
  while(n > 0){
    if(n % 2 == 1) r = r * p ;
    p *= p ;
    n /= 2 ;
  }
  //@ assert is_power(p, n, 1) ;
  
  return r ;
}
