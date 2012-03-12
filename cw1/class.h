
class Klasa {
	private:
		double testDouble;
	public:
		void setTestDouble(double d){
			testDouble = d;
		}
		
		double getTestDouble(){
			return testDouble;
		}

		bool isBiggerThan(double d){
			if(d > testDouble){
				return true;
			}
			else{
				return false;
			}
		}
		
		bool isSmallerThan(double d){
			if(d > testDouble){
				return true;
			}
			else{
				return false;
			}
		}
		
		bool isEven(int d){
			if(d%2 == 0){
				return true;
			}
			else{
				return false;
			}
		}
};
