#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <tuple>
#include <sstream>


using namespace std;

bool numbers(string str) {
    for (char a : str) {
        if (!isdigit(a) and a != '-') return false;
    }
    return true;
}

int sizen(string arrayname) {
    fstream file;
    file.open("chunk/" + arrayname + ".txt", ios::in);
    if (!file.is_open()) {
        cout << "2Ошибка открытия файла";
        exit(1);
    }
    string line;
    int n = 0;

    while (getline(file, line)) {
        if (line.length() != 0) {
            n++;
        }
    }

    file.close();
    return n;
}

int sizem(string arrayname, int n) {
    fstream file;
    file.open("chunk/" + arrayname + ".txt", ios::in);
    if (!file.is_open()) {
        cout << "1Ошибка открытия файла";
        exit(1);
    }
    string line;
    int m = 0;
    //getline(file, line);

    //int a = n;
    //int ncount=0;
    string x;
    int m1 = numeric_limits<int>::max();
    while (getline(file, line)) {
        stringstream ss(line);
        m = 0;
        //if (file.eof() == true) break;
        while (getline(ss, x, ' ')) {
            m++;
            //if (file.eof()==true) break;
            //ncount++;
        }
        if (m < m1) m1 = m;
        

    }
    file.close();
    return m1;

}



int** chitka(string filename, int n, int m) {
    fstream file;
    file.open("chunk/" + filename + ".txt", ios::in);
    if (!file.is_open()) {
        cout << ("Ошибка открытия файла");
        exit(1);
    }

    int** mas = new int* [n];
    int i = 0;
    string line;
    while (getline(file, line)) {
        int* stroka = new int[m];
        stringstream ss(line);

        int j = 0;
        string x;
        while (getline(ss, x, ' ')) {
            // cout << x << '#';
            if (j > m) break;
            stroka[j] = atof(x.c_str());
            j++;

        }
        // cout << endl;

        mas[i] = stroka;
        i++;
    }
    return mas;
}


int sqrt(int a) {
    int r = pow(a, 1 / 2);
    return r;
    

}
int findminx(int* arrx){
    int min = numeric_limits<int>::max();
    for (unsigned i = 0; i < 4; i++) {
        if (min > arrx[i]) min = arrx[i];
    }
    return min;
}
int findmaxx(int* arrx) {
    int max=0;
    
    for (unsigned i = 0; i < 4; i++) {
        if (max < arrx[i]) max = arrx[i];
        
    }
    return max;
}


bool check(int* arrx, int* arry) {
    bool TrueCounter;
    
    
    if (((arrx[0] - arrx[2]) * (arry[1] - arry[2]) - (arrx[1] - arrx[2]) * (arry[0] - arry[2]) == 0) & ((arrx[1] - arrx[3]) * (arry[2] - arry[3]) - (arrx[2] - arrx[3]) * (arry[1] - arry[3]) == 0)) {
         TrueCounter=true;
           
    }
        
    if (TrueCounter == true) {
        if (sqrt((arrx[1] - arrx[0]) * (arrx[1] - arrx[0]) + (arry[1] - arry[0]) * (arry[1] - arry[0])) \
            == sqrt((arrx[3] - arrx[2]) * (arrx[3] - arrx[2]) + (arry[3] - arry[2]) * (arry[3] - arry[2])) || \
            sqrt((arrx[3] - arrx[1]) * (arrx[3] - arrx[1]) + (arry[3] - arry[1]) * (arry[3] - arry[1])) \
            == sqrt((arrx[2] - arrx[0]) * (arrx[2] - arrx[0]) + (arry[2] - arry[0]) * (arry[2] - arry[0]))) {
            return true;
        }
           
        
    }
    else {
        return false;
    }

    }


bool peremoga(int** mas, int n, int m) {
    
    for (int i = 0; i < n-3; i++) {
        for (int j = 1; j < 2;) {
            int* arrx = new int[4];
            int* arry = new int[4];
            for (int k = 0; k < 4; k++) {
                arrx[k] = mas[i + k][j];
                arry[k] = mas[i + k][j+1];
                bool a = check(arrx, arry);
                if (a == true) {
                    return true;
                    }
                else {
                    return false;
                
   
                }
            }
            
        }
    }
}
int* peremogax(int** mas, int n, int m) {
    for (int i = 0; i < n - 3; i++) {
        for (int j = 1; j < 2;) {
            int* arrx = new int[4];
            int* arry = new int[4];
            for (int k = 0; k < 4; k++) {
                arrx[k] = mas[i + k][j];
                arry[k] = mas[i + k][j];
                bool a = check(arrx, arry);
                return arrx;

                
            }

        }
    }
}
int* peremogay(int** mas, int n, int m) {
    for (int i = 0; i < n - 3; i++) {
        for (int j = 1; j < 2;) {
            int* arrx = new int[4];
            int* arry = new int[4];
            for (int k = 0; k < 4; k++) {
                arrx[k] = mas[i + k][j];
                arry[k] = mas[i + k][j];
                return arry;

                
            }

        }
    }
}
int ihatenmax(int max, int* arrx) {
    int n = 0;
    for (unsigned i = 0; i < 4; i++) {
        if (max == arrx[i]) n = max;
        
    }
    return n;
}
int ihatenmin(int min, int* arrx) {
    int n = 0;
    for (unsigned i = 0; i < 4; i++) {
        if (min == arrx[i]) n = min;

    }
    return n;
}
int bruhtella(int n, int m, int* arrx) {
    n = 0;
    for (int i = 0; i < 4; i++) {
        if (arrx[i] != n && arrx[i] != m) {
            if (arrx[i] > n) n = arrx[i];
        }
    }
    return n;

}
int bruhtellanum(int n, int* arrx) {
    int nn = 0;
    int a=0;
    for (int i = 0; i < 4; i++) {
        if (arrx[i] == n) a = i;
        return a;
    }
}
double findcentreandraduism(int mid, int min, int max, int* arrx, int* arry) {
    double xcen = (arrx[max] - arrx[min]) / 2;
    double ycen = (arry[max] - arry[min]) / 2;
    double mradius = sqrt((arrx[mid] - xcen) * (arrx[mid] - xcen)+ (arry[mid] - ycen) * (arry[mid] - ycen));
    return mradius;
    






}
double findcentreandraduisM(int mid, int min, int max, int* arrx, int* arry) {
    double xcen = (arrx[max] - arrx[min]) / 2;
    double ycen = (arry[max] - arry[min]) / 2;
    double Mradius = sqrt((arrx[max] - xcen) * (arrx[max] - xcen) + (arry[max] - ycen) * (arry[max] - ycen));
    return Mradius;
}

int prinadleshnost(int** mas, double r, double R, int n, int* arrx, int* arry) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 1; j++) {
            double a = mas[i][j] * mas[i][j] + mas[i][j + 1] * mas[i][j + 1];
            /*if (a >= r && a <= R && (arry[0] - arry[1]) * mas[i][j] + (arrx[0] * arry[1] - arrx[1] * arry[0]) < -(arrx[1] - arrx[0]) * mas[i][j + 1]) {
                count++;
                cout << count;
            }*/
        }
    }
    return count;
}
int main() {
    cout << "Автор: Безруков Павел \n"
        "Группа: 1302 \n"
        "Дата начала: 26.11.2021 \n"
        "Дата конца: 26.11.2021 \n"
        "Версия: 5.0.0 \n" << endl;

    string filename = "A";
    int n = sizen(filename);
    int m = sizem(filename, n);
    int** mas = chitka(filename, n, m);
    int* arrx = new int[4];
    int* arry = new int[4];
    int count1 = 0;
    for (int i = 0; i < n; i++) {
        cout << n; 
        cout << peremoga(mas, n, m);
        if (peremoga(mas, n, m) == true) {
            arrx = peremogax(mas, n, m);
            arry = peremogay(mas, n, m);
            int max = findmaxx(arrx);
            int min = findminx(arrx);
            int ny = ihatenmax(max, arrx);
            int nyx = ihatenmin(min, arrx);
            int mid = bruhtella(ny, nyx, arrx);
            int nyxmid = bruhtellanum(mid, arrx);
            double r = findcentreandraduism(mid, min, max, arrx, arry);
            double R = findcentreandraduisM(mid, min, max, arrx, arry);
            int count = prinadleshnost(mas, r, R, n, arrx, arry);
            if (count1 < count) count1 = count;
            cout << count1;
            
        }
        else {
            cout << "Error: No spots\n";
        }
    }
    cout << count1;
}