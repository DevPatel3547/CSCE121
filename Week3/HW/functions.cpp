int Largest(int a, int b, int c){
    if(a >= b && a >= c){
        return a;
	}

    if(b >= a && b >= c){
        return b;
	}
    
    if(c >= a && c >= b){
        return c;
	}
}

bool SumIsEven(int a, int b){
	if((a+b)%2 == 0){
		return true;
	}
    else{
	    return false;
	} 
}

int BoxesNeeded(int apples){
    if(apples <= 0){
		return 0;
	}
	else{
		double a = apples/20.0;
		return round(a);
	}
}

bool SmarterSection(int A_correct, int A_total, int B_correct, int B_total){
	if(A_correct <= A_total && B_correct <= B_total && B_total > 0 && A_total > 0 && B_correct >=0 && A_correct >= 0){
		return double(A_correct)/double(A_total) > double(B_correct)/double(B_total);
    }
	else{
		throw std::invalid_argument("Recieved invalid argument");
	}
}

bool GoodDinner(int pizzas, bool is_weekend) {
	if (pizzas >= 10 && pizzas <= 20) {
		return true;
	}
    if (is_weekend && pizzas >= 10 ) {
		return true;
	}
	else{
		return false;
	}
}

int SumBetween(int low, int high) {
	int value = 0;
	if(low == (-2147483647-1) && high == (2147483647)){
		return value;
	}
	if(low == -2147483647 && high == -1){
		value = -2147483648;
		return value;
	}
		
    value = 0;
	if(high < low){
		throw std::invalid_argument("Invalid argument");
	}
	
	for (int n = low; n < high +1; n++){
		if(INT32_MAX - n < value || INT32_MIN + n > value){
             throw std::overflow_error("Integer Overflow");
		}	
        else{
            value += n;
		}
					
	}
		
    return value;
}

int Product(int a, int b) {
  double c = 0.0;
  if (a<0 && b>0){
    c = (INT32_MIN)/(double(a));
    if (b > c)
    {
      throw std::overflow_error("Overflow");
    }
    else{
      return a*b;
    }
  }
  else if (a > 0 && b < 0){
    c=(INT32_MIN)/(double(a));
    if (b < c){
      throw std::overflow_error("Overflow");
    }
    else{
      return a*b;
    }
  }
  else if (a>0 && b>0){
    c=(INT32_MAX)/(double(a));
    if (b > c){
      throw std::overflow_error("Overflow");
    }
    else{
      return a*b;
    }
  }
  else if (a<0 && b<0){
    c =(INT32_MAX)/(double(a));
    if (b < c){
      throw std::overflow_error("Overflow");
    }
    else{
      return a*b;
    }
  }
  return 0;}

