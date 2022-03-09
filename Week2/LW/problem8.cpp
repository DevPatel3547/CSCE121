#include <iostream>

bool f(bool x, bool y, bool z) {
  bool value;	
  if(x == 0 && y ==0  && z == 0 ){
	  value = false;
  }
  else if(x == 1 && y != 1 && z != 1){
	  value = true;
  }
  else if(x != 1 && y != 1 && z == 1){
	  value = true;
  }
  else if(x != 1 && y == 1 && z != 1){
	  value = true;
  }
  else if(x != 1 && y == 1 && z == 1){
	  value = true;
  }
  else if(x == 1 && y == 1 && z == 1){
	  value = true;
  }
  else{
	  value = false;
  }
	  
  
 
  return value;
}