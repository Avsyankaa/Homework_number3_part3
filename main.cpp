#include <iostream>
#include <string.h>
#include <cstdio>
#include <fstream>
using namespace std;
void print_matrix (int **&Matrix, int &m, int &n) {
    if (Matrix==nullptr) cout<< "Matrix is empty"<< endl;
    else {
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) cout<< Matrix[i][j]<< " ";
            cout<< endl;
        }
    }
}
void deleting_Matrix (int **&Matrix, int &m, int &n) {
    if (Matrix!=nullptr) {
        for (int i=0; i<m; i++) delete[]Matrix[i];
        delete [] Matrix;
    }
}
void sum_matrix (int **&Matrix, int &m, int &n) {
    if (Matrix==nullptr) cout<< "Matrix is empty"<< endl;
    else {
        cout << "Enter martix "<< m<<"x"<<n<<":"<<endl;
        int **Matrix_addened;
        Matrix_addened= new int *[m];
        for (int i=0; i<m; i++) Matrix_addened[i]= new int [n];
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++)
                cin >> Matrix_addened[i][j];
        }
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) Matrix[i][j]= Matrix[i][j]+ Matrix_addened[i][j];
        }
        deleting_Matrix( Matrix_addened, m, n);
    }
}
void multiply_matrix (int **&Matrix, int &m, int &n) {
    if (Matrix==nullptr) cout<< "Matrix is empty"<< endl;
    else {
        cout << "Enter a size of matrix:" << endl;
        string size;
        cin >> size;
        int m_multiply2, n_multiply2, k=0;
        string m_multiply_str, n_multiply_str;
        while (size[k]!= 'x') {
            m_multiply_str= m_multiply_str+ size[k];
            k++;
        }
        k++;
        while (k!= size.length()) {
            n_multiply_str= n_multiply_str+ size[k];
            k++;
        }
        k=0;
        m_multiply2= atoi (m_multiply_str.c_str());
        n_multiply2= atoi (n_multiply_str.c_str());
        if ((n!= m_multiply2) || (n_multiply2==0)) cout << "Uncorrect size!!!" << endl;
        else {
            int **Matrix_multiply2;
            Matrix_multiply2= new int *[m_multiply2];
            for (int i=0; i<m_multiply2; i++)  Matrix_multiply2[i]= new int [n_multiply2];
            for (int i=0; i<m_multiply2; i++) {
                for (int j=0; j<n_multiply2; j++)
                    cin >> Matrix_multiply2[i][j];
            }
            int **Matrix_multiply1;
            Matrix_multiply1= new int *[m];
        while (size[k]!= 'x') {
            m_multiply_str= m_multiply_str+ size[k];
            k++;
        }
        k++;
        while (k!= size.length()) {
            n_multiply_str= n_multiply_str+ size[k];
            k++;
        }
        k=0;
        m_multiply2= atoi (m_multiply_str.c_str());
        n_multiply2= atoi (n_multiply_str.c_str());
        if ((n!= m_multiply2) || (n_multiply2==0)) cout << "Uncorrect size!!!" << endl;
        else {
            int **Matrix_multiply2;
            Matrix_multiply2= new int *[m_multiply2];
            for (int i=0; i<m_multiply2; i++)  Matrix_multiply2[i]= new int [n_multiply2];
            for (int i=0; i<m_multiply2; i++) {
                for (int j=0; j<n_multiply2; j++)
                    cin >> Matrix_multiply2[i][j];
            }
            int **Matrix_multiply1;
            Matrix_multiply1= new int *[m];
            for (int i=0; i<m; i++) Matrix_multiply1[i]= new int [n];
            for (int i=0; i<m; i++) {
                for (int j=0; j<n; j++)
                    Matrix_multiply1[i][j] = Matrix [i][j];
            }
            int m_multiply1 = m;
            int n_multiply1 = n;
            deleting_Matrix (Matrix, m, n);
            n= n_multiply2;
            Matrix= new int *[m];
            for (int i=0; i<m; i++) Matrix[i]= new int [n];
            for (int i=0; i<m; i++) {
                for (int j=0; j<n; j++)
                    Matrix[i][j]= 0;
            }
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    for (int z = 0; z < m_multiply2; z++)
                        Matrix[i][j] = Matrix[i][j] + Matrix_multiply1[i][z] * Matrix_multiply2[z][j];
                }
            }
            deleting_Matrix (Matrix_multiply1, m_multiply1, n_multiply1);
            deleting_Matrix (Matrix_multiply2, m_multiply2, n_multiply2);
        }
    }
}
void transpose_matrix ( int **&Matrix, int &m, int &n) {
    if (Matrix==nullptr) cout<< "Matrix is empty"<< endl;
    else {
        int **Matrix_before_tr;
        Matrix_before_tr= new int *[m];
        for (int i=0; i<m; i++) Matrix_before_tr[i]= new int [n];
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++)
                Matrix_before_tr[i][j] = Matrix [i][j];
        }
        int m_before_tr=m;
        int n_before_tr=n;
        deleting_Matrix (Matrix, m, n);
        swap (m,n);
        Matrix= new int *[m];
        for (int i=0; i<m; i++) Matrix[i]= new int [n];
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++)
                Matrix[i][j]= Matrix_before_tr [j][i];
        }
        deleting_Matrix (Matrix_before_tr, m_before_tr, n_before_tr);
    }
}
void save_matrix_to_the_file (int **&Matrix, int &m, int &n) {
    if (Matrix==nullptr) cout<< "Matrix is empty!!!";
    else {
        string file_name;
        string decision = "yes";
        cout << "Enter a name of the file:" << endl;
        cin >> file_name;
        fstream File, File1;
        File1.open (file_name, ios::in);
        if (File1.is_open()) {
            cout << "Do you want to rewrite file? (yes/ no)" << endl;
            cin >> decision;
        }
        File1.close();
        File.open (file_name, ios::out);
        if ((decision == "y") || (decision == "yes") || (decision == "Y") ||
                (decision == "Yes") || (decision == "YES")) {
            for (int i=0; i<m; i++) {
                for (int j=0; j<n; j++) File<< Matrix[i][j]<< " ";
                File<< endl;
            }
        }
        File.close();
    }
}
void download_matrix_from_file (int **& Matrix, int &m, int &n) {
    if (Matrix!= nullptr) cout << "Matrix already exists!!!";
    else {
        cout << "Enter a way to the file"<< endl;
        string way_to_the_file;
        string result_way;
        cin >> way_to_the_file;
        int k=0;
        while (k!= way_to_the_file.length()) {
            if ( way_to_the_file[k] == '/') {
                result_way= result_way+ "\\"+"\\";
            } else result_way= result_way+ way_to_the_file[k];
            k++;
        }
        result_way= "C:"+ result_way;
        fstream File;
        File.open (result_way, ios::in);
        if (File.is_open()) {
            string first_string;
            getline (File,first_string);
            for (int i=0; i< first_string.length(); i++) {
                if (first_string[i]==' ') n++;
            }
            while (!File.eof()) {
                getline (File, first_string);
                m++;
            }
            File.close();
            File.open (result_way, ios::in);
            Matrix= new int *[m];
            for (int i=0; i<m; i++) Matrix[i]= new int [n];
            for (int i=0; i<m; i++) {
                for (int j=0; j<n; j++) {
                    File >> first_string;
                    Matrix[i][j] = atoi( first_string.c_str());
                }
            }
        } else cout << "Error. No such file or directory!!!" << endl;
        File.close();
    }
}
void Menu (int **&Matrix, int &m, int &n) {
    int choise;
    string exit;
    while ((exit != "y") && (exit != "yes") && (exit != "Y") && (exit != "Yes")
            && (exit != "YES")) {
        cout << "Select one of the operations:" << endl;
        cout << "1.Print the matrix" << endl;
        cout << "2.Sum the matrix" << endl;
        cout << "3.Multiply the matrix" << endl;
        cout << "4.Transpose the matrix" << endl;
        cout << "5.Save to the file" << endl;
        cout << "6.Download from the file" << endl;
        cout << "7.Sort the matrix" << endl;
        cout << "8.Complete the program" << endl;
        cin >> choise;
        switch (choise) {
        case 1:
            print_matrix ( Matrix, m, n);
            break;
        case 2:
            sum_matrix ( Matrix, m, n);
            break;
        case 3:
            multiply_matrix (Matrix, m, n);
            break;
        case 4:
            transpose_matrix (Matrix, m, n);
            break;
        case 5:
            save_matrix_to_the_file (Matrix, m, n);
            break;
        case 6:
            download_matrix_from_file(Matrix, m, n);
            break;
        case 8:
            cout << "Do you want to leave program? ( yes, no )" << endl;
            cin >> exit;
            if ((exit == "y") || (exit == "yes") || (exit == "Y") ||
                    (exit == "Yes") || (exit == "YES"))
                cout << "Good by!";
            break;
        }
    }
}

int main (int argc, char *argv []) {
    string m_str,n_str;
    int m,n,integer1;
    int k=0;
    int **Matrix;
    if (argc==1) {
        m=n=0;
        Matrix= nullptr;
    } else {
        while (argv[1][k]!= 'x') {
            m_str= m_str+ argv[1][k];
            k++;
        }
        k++;
        while (k!= strlen(argv[1])) {
            n_str= n_str+ argv[1][k];
            k++;
        }
        k=0;
        m= atoi (m_str.c_str());
        n= atoi (n_str.c_str());
        if ((m==0)||(n==0)) Matrix=nullptr;
        else {
            Matrix= new int *[m];
            for (int i=0; i<m; i++) Matrix[i]= new int [n];
            for (int i=0; i<m; i++) {
                for (int j=0; j<n; j++)
                    Matrix[i][j]= 0;
            }
            if ( argc == 2) { } else {
                if (argc == 3) {
                    string matrix_array;
                    matrix_array = argv[2];
                    string integer_str;
                    for (int i=0; i< m; i++) {
                        for (int j=0; j<n; j++) {
                            if (k< matrix_array.length()) {
                                for (int z = k; z < matrix_array.length(); z++) {
                                    if (matrix_array[z] == ',') {
                                        k++;
                                        break;
                                    }
                                    integer_str = integer_str + matrix_array[z];
                                    k++;
                                }
                                if (integer_str != "") {
                                    integer1 = atoi(integer_str.c_str());
                                    Matrix[i][j]= integer1;
                                }
                                integer_str = "";
                            }
                        }
                    }

                } else {
                    int z = 2;
                    for (int i=0; i< m; i++) {
                        for (int j=0; j<n; j++) {
                            if (z < argc) {
                                integer1 = atoi(argv[z]);
                                Matrix[i][j]= integer1;
                                z++;
                            }
                        }
                    }
                }
            }
        }
    }
    Menu( Matrix, m,n);
    deleting_Matrix (Matrix, m,n);
}
