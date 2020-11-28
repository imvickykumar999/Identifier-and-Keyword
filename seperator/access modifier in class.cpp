#include <iostream>
using namespace std;

class character
{
	private:
		int health;
		
	public:
		character(){
			health = 100;
		}
		int gethealth(){
			return health;
		}
		void gethurt(int hurtvalue){
			health -= hurtvalue;
		}	
};

int main()
{
	character player1;
	cout << player1.gethealth() << endl;
	
	player1.gethurt(10);
	cout << player1.gethealth() << endl;
}
