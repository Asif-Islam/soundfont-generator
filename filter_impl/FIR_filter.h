class FIRFilter 
{
 public:

	 // The FIR Filter must always be defined with a filter length, input length.
	 FIRFilter(int filter_length, int input_length);

	 // Load or initialize coefficients 
	 void LoadorInitCoeffecients(const char* coefficients_file);

	 // Get the length of the filter.
	 int GetFilterLength();

	 // Set the length of the filter.
	 void SetFilterLength(int filter_length);

	 // Get the number of samples to be processed per filter iteration.
	 int GetInputLength();

	 // Set the number of samples to be processed per filter iteration.
	 void SetInputLength(int input_length);

	 // Print debugging of filter;
	 void PrintFilterProperties();

 private:

	 // Defines the order of the filter, i.e. the number of coefficients.
	 int filter_length_;

	 // Defines the number of samples to be processed per filter iteration.

	 // Coefficients of the filter.
	 float *coefficients_;
};
