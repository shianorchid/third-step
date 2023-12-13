#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// 配列の要素数
#define NUM_STUDENTS 20

// 関数のプロトタイプ宣言
double calculate_mean(int scores[], int n);
double calculate_std_dev(int scores[], int n, double mean);
void calculate_z_scores(int scores[], int n, double mean, double std_dev, double z_scores[]);
void sort_scores_desc(int scores[], int n);
int calculate_sum(int scores[],int n);

int main() {
    // 理科と英語のテストの点数
    int science_scores[NUM_STUDENTS] = {65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70};
    int english_scores[NUM_STUDENTS] = {44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84};

    // 平均点の計算
    double science_mean = calculate_mean(science_scores, NUM_STUDENTS);
    double english_mean = calculate_mean(english_scores, NUM_STUDENTS);

    //合計点
    int science_sum = calculate_sum(science_scores, NUM_STUDENTS);
    int english_sum = calculate_sum(english_scores, NUM_STUDENTS);

    // 標準偏差の計算
    double science_std_dev = calculate_std_dev(science_scores, NUM_STUDENTS, science_mean);
    double english_std_dev = calculate_std_dev(english_scores, NUM_STUDENTS, english_mean);

    // 偏差値の計算と表示
    double science_z_scores[NUM_STUDENTS];
    double english_z_scores[NUM_STUDENTS];

    calculate_z_scores(science_scores, NUM_STUDENTS, science_mean, science_std_dev, science_z_scores);
    calculate_z_scores(english_scores, NUM_STUDENTS, english_mean, english_std_dev, english_z_scores);

    
    printf("理科の平均点：%lf点, 理科の標準偏差：%lf, 理科の合計点：%d点\n",science_mean,science_std_dev,science_sum);
    printf("英語の平均点：%lf点, 英語の標準偏差：%lf, 英語の合計点：%d点\n",english_mean,english_std_dev,english_sum);

    printf(" :) \n");
    // 偏差値と元の点数を表示
    printf("生徒\t理科点数\t理科偏差値\t英語点数\t英語偏差値\n");
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        printf("%d\t%d\t%.2f\t\t%d\t%.2f\n", i + 1, science_scores[i], science_z_scores[i], english_scores[i], english_z_scores[i]);
    }

    // 元の点数で並び替えて表示
    sort_scores_desc(science_scores, NUM_STUDENTS);
    printf("\n理科の点数（高い順）:\n");
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        printf("%d ", science_scores[i]);
    }

    sort_scores_desc(english_scores, NUM_STUDENTS);
    printf("\n英語の点数（高い順）:\n");
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        printf("%d ", english_scores[i]);
    }

    return 0;
}

// 平均値の計算
double calculate_mean(int scores[], int n) {
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += scores[i];
    }
    return sum / n;
}

// 合計点の計算
int calculate_sum(int scores[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += scores[i];
    }
    return sum;
}

// 標準偏差の計算
double calculate_std_dev(int scores[], int n, double mean) {
    double sum_squares = 0;
    for (int i = 0; i < n; ++i) {
        sum_squares += pow(scores[i] - mean, 2);
    }
    return sqrt(sum_squares / n);
}

// 偏差値の計算
void calculate_z_scores(int scores[], int n, double mean, double std_dev, double z_scores[]) {
    for (int i = 0; i < n; ++i) {
        z_scores[i] = (scores[i] - mean) / std_dev * 10 + 50;
    }
}

// 配列を降順にソート
void sort_scores_desc(int scores[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (scores[j] < scores[j + 1]) {
                // スワップ
                int temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }
}

