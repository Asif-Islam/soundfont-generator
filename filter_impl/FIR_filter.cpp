#include "FIR_filter.h"

#include "assert.h"
#include "iostream"

FIRFilter::FIRFilter(int filter_length, int input_length) 
{
	assert(filter_length > 0);
	filter_length_ = filter_length;
	assert(input_length_ > 0);
	input_length_ = input_length;
	coefficients_ = new float[filter_length];
	memset(coefficients_, 0, filter_length_ * sizeof(float));
	sample_buffer_ = new float[input_length + filter_length - 1];
	memset(sample_buffer_, 0, (input_length + filter_length - 1) * sizeof(float));
}

FIRFilter::~FIRFilter() {
	delete[] coefficients_;
}

void FIRFilter::LoadCoeffecients(const char* coefficients_file) {
}

int FIRFilter::GetFilterLength() {
	return filter_length_;
}

int FIRFilter::GetInputLength()
{
	return input_length_;
}

void FIRFilter::ApplyFilter(float* input, float* output, int length)
{
	assert(input != NULL);
	assert(output != NULL);
	assert(length > 0);

	// Implement accumulation by the form y(n) = sum( h(k) * x(n-k) ) for k = 0 to filter_length.
	
	// Move input data into the buffer.
	memcpy(&sample_buffer_[filter_length_ - 1], input, length * sizeof(float));
	
	// Accumulation step for each timestemp.
	for (int i = 0; i < length; ++i)
	{
		float sum = 0;
		for (int j = 0, k = filter_length_ - 1 + i; j < filter_length_; ++j, --k)
		{
			sum += coefficients_[j] * sample_buffer_[k];
		}
		output[i] = sum;
	}

	// Move data back in time in preperation for next set of samples.
	memmove(&sample_buffer_[0], &sample_buffer_[length], (filter_length_ - 1) * sizeof(float));
}


void FIRFilter::PrintFilterProperties()
{
	std::cout << "Filter Length: " << filter_length_ << std::endl;
	std::cout << "Input Length: " << input_length_ << std::endl;
	std::cout << "Printing coefficients..." << std::endl;
	for (int i = 0; i < filter_length_; ++i) 
	{
		std::cout << coefficients_[i] << ", " << std::endl;
	}
}
