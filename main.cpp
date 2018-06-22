#include <iostream>
#include <cstdlib>


using namespace std;

// Сортировка пузырьком
void bubbleSort(char *a, int n){
	int x;

	for(int i=0; i < n; i++){
		for(int j = n-1; j > i; j-- ){
			if(a[j-1] > a[j]){
				x=a[j-1];
				a[j-1]=a[j];
				a[j]=x;
			}
		}
	}
}

// Проверка на вхождение
int inclusion(char *a, char *b, int n, int m){
	int i = 0,	j = 0;
	for(; i < n && j < m;){
		if(a[i] < b[j]){
			return 0;	// А отсутствует в B 
		}else if(a[i] > b[j]){
			j++;
		}else{
			i++; 
			j++;
		}
	}
	if(!a[i]){
		return 1;
	}else{
		return 0;
	}
	return 0;
}

// Объединение
int merger(char *a, char *b, char *c, int n, int m){
	int i = 0,	j = 0, k = 0;
	for(; i < n && j < m;){
		if(a[i] < b[j]){
			c[k++] = a[i++];
		}else if(a[i] > b[j]){
			c[k++] = b[j++];
		}else{
			c[k++] = a[i];
			i++; 
			j++;
		}
	}
	if(a[i]){
		for(;i < n; i++, k++){
			c[k] = a[i];
		}
	}else if(b[j]){
		for(;j < m; j++, k++){
			c[k] = b[j];
		}
	}

	return 0;
}

// Пересечение
int intersection(char *a, char *b, char *c, int n, int m){
	int i = 0,	j = 0, k = 0;
	for(; i < n && j < m;){
		if(a[i] < b[j]){
			i++;
		}else if(a[i] > b[j]){
			j++;
		}else{
			c[k++] = a[i];
			i++; 
			j++;
		}
	}

	return 0;
}

// Разность
int difference(char *a, char *b, char *c, int n, int m){
	int i = 0,	j = 0, k = 0;
	for(; i < n && j < m;){
		if(a[i] < b[j]){
			c[k++] = a[i++];
		}else if(a[i] > b[j]){
			j++;
		}else{
			i++; 
			j++;
		}
	}
	if(a[i]){
		for(;i < n; i++, k++){
			c[k] = a[i];
		}
	}

	return 0;
}

// Вывод множества
int printM(char *a){
	for(int i = 0;; i++){
		if(!a[i]) break;
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}

int printMultiplicityAll(char *a, char *b, char *c){
	system("clear");

	cout << "A: ";
	printM(a);
	cout << "B: ";
	printM(b);
	cout << "C: ";
	printM(c);

	cout << "\n\nВведите любой символ.. ";

	cin.get(); cin.get();

	return 0;
}

int addM(char *a, int n, int k){
	char *buff = new char[1];

	printM(a);
	for(int i = n; i < n+k;){
		cin >> buff[0];

		if((buff[0] >= 'A' && buff[0] <= 'Z') || (buff[0] >= 'a' && buff[0] <= 'z')){
			if(inclusion(buff, a, 1, n+i) == 0){
				a[i++] = buff[0];
			}else{
				cout << "Данный элемент уже есть в множестве" << endl;
			}
		}else{
			cout << "Введите корректный элемент" << endl;
		}
	}

	bubbleSort(a, n+k);

	return n+k;
}

int clearM(char *a){
	delete a;
	a = new char[52];

	return 0;
}

int main(void){
	char *a, *b, *c;
	int n = 0, m = 0;
	int pMenu, k;

	a = new char[52];
	b = new char[52];
	c = new char[52];

	/*a[0] = 'A'; 
	//a[1] = 'B';
	//a[2] = 'C';
	b[0] = 'C';
	//b[1] = 'D';

	cout << inclusion(a, b, 1, 1);
	//difference(b, a, c, m, n);

	printM(c);*/
	for(int menu;;){
		system("clear");

		cout << "Выберите нужный пункт меню, введя соответствующее число" << endl;
		cout << "1. Ввести значения для множества" << endl;
		cout << "2. Объединение множеств" << endl;
		cout << "3. Пересечение множеств" << endl;
		cout << "4. Разность множеств" << endl;
		cout << "5. Вывод множеств" << endl;
		cout << "0. Выход из программы" << endl;

		cin >> menu;

		switch(menu){
			case 1:
				system("clear");

				cout << "Какое множество? \n1. Добавить элементы в множество A\n2. Добавить элементы в множество B" << endl;
				cin >> pMenu;

				if(pMenu == 1){
					cout << "Сколько элементов добавить?" << endl;
					cout << "Для множества A доступно " << 52-n << " элементов." << endl;

					cin >> k;

					if(n+k <= 52){
						n = addM(a, n, k);
					}else{
						cout << "Невозможно ввести столько элементов в данное множество" << endl;
					}
				}else if(pMenu == 2){
					cout << "Сколько элементов добавить?" << endl;
					cout << "Для множества B доступно " << 52-m << " элементов." << endl;

					cin >> k;

					if(m+k <= 52){
						m = addM(b, m, k);
					}else{
						cout << "Невозможно ввести столько элементов в данное множество" << endl;
					}
				}else{
					cout << "Был неправельно выбран пункт меню" << endl;
				}
				break;
			case 2:
				clearM(c);
				merger(a, b, c, n, m);

				printMultiplicityAll(a, b, c);
				break;
			case 3:
				clearM(c);
				intersection(a, b, c, n, m);

				printMultiplicityAll(a, b, c);
				break;
			case 4:
				cout << "Какое из какого множества вычетать? \n1. A из B\n2. B из A" << endl;
				cin >> pMenu;

				if(pMenu == 1){
					clearM(c);
					difference(a, b, c, n, m);
				}else if(pMenu == 2){
					clearM(c);
					difference(b, a, c, m, n);
				}else{
					cout << "Был неправельно выбран пункт меню" << endl;
				}

				printMultiplicityAll(a, b, c);
				
				break;
			case 5:
				printMultiplicityAll(a, b, c);
				break;
			case 0:
				return 0;
				break;
			default:
				break;
		}
	}
	return 0;
}