#include <stdio.h>  // fprintf
#include <stdlib.h> // exit

#include "q.h"      // need 9 functions


int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage of program: ./q.out input_file_name output-file-name\n");
    exit(EXIT_FAILURE);
  }

  int num_val;
  double *pgrades = read_data(argv[1], &num_val);
  double min_val = min(pgrades, pgrades+num_val);
  double max_val = max(pgrades, pgrades+num_val);
  double avg_val = average(pgrades, pgrades+num_val);
  double var_val = variance(pgrades, pgrades+num_val);
  double sd_val  = std_dev(pgrades, pgrades+num_val);
  double med_val = median(pgrades, num_val);

  double ltr_grades[TOT_GRADE];
  ltr_grade_pctg(pgrades, pgrades+num_val, ltr_grades);
  free(pgrades);

  FILE *out_stream = fopen(argv[2], "w");
  if (NULL == out_stream) {
    fprintf(stderr, "Unable to create output file %s\n", argv[2]);
    exit(EXIT_FAILURE);
  }
  fprintf(out_stream, "Total number of grades: %d\n", num_val);
  fprintf(out_stream, "\nLetter Grade |  %%age \n");
  fprintf(out_stream, "----------------------\n");
  char cg[TOT_GRADE] = {'A', 'B', 'C', 'D', 'F'};
  for (int i = 0; i < TOT_GRADE; ++i) {
    fprintf(out_stream, "%6c       | %5.2f\n", cg[i], ltr_grades[i]);
  }
  fprintf(out_stream, "\nMaximum grade     : %6.2f\n", max_val);
  fprintf(out_stream, "Minimum grade     : %6.2f\n", min_val);
  fprintf(out_stream, "Average grade     : %6.2f\n", avg_val);
  fprintf(out_stream, "Variance          : %5.2f\n", var_val);
  fprintf(out_stream, "Standard deviation: %6.2f\n", sd_val);
  fprintf(out_stream, "Median grade      : %6.2f\n", med_val);
  exit(EXIT_SUCCESS);
}
