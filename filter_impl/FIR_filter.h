class FIRFilter 
{
 public:

	 // The FIR Filter must always be defined with a filter length, input length.
	 FIRFilter(int filter_length, int input_length);

	 // Destructor.
	 ~FIRFilter();

	 // Load or initialize coefficients 
	 void LoadCoeffecients(const char* coefficients_file);

	 // Get the length of the filter.
	 int GetFilterLength();

	 // Get the number of samples to be processed per filter iteration.
	 int GetInputLength();

	 // Runs a filter iteration on the input data.
	 void ApplyFilter(float* input, float* output, int length);

	 // Print debugging of filter;
	 void PrintFilterProperties();

 private:

	 // Defines the order of the filter, i.e. the number of coefficients.
	 int filter_length_;

	 // Defines the number of samples to be processed per filter iteration.
	 int input_length_;

	 // Coefficients of the filter.
	 float *coefficients_;

	 // Buffer to store input samples
	 float *sample_buffer_;
};
