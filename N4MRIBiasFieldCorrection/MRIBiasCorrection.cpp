void MRIBiasCorrection()
{
	/**
	* Calculate the log of the input image.
	*/

	/**
	* Remove possible nans/infs from the log input image.
	*/


	/**
	* Provide an initial log bias field of zeros
	*/


	/**
	* Iterate until convergence or iterative exhaustion.
	*/



	/**
	* Sharpen the current estimate of the uncorrected image.
	*/

	/**
	* Smooth the residual bias field estimate and add the resulting
	* control point grid to get the new total bias field estimate.
	*/


	/**
	* Divide the input image by the bias field to get the final image.
	*/

}


void SharpenImage()
{
	/**
	* Build the histogram for the uncorrected image.  Store copy
	* in a vnl_vector to utilize vnl FFT routines.  Note that variables
	* in real space are denoted by a single uppercase letter whereas their
	* frequency counterparts are indicated by a trailing lowercase 'f'.
	*/


	/**
	* Create the intensity profile (within the masked region, if applicable)
	* using a triangular parzen windowing scheme.
	*/


	/**
	* Determine information about the intensity histogram and zero-pad
	* histogram to a power of 2.
	*/


	/**
	* Instantiate the 1-d vnl fft routine
	*/


	/**
	* Create the Gaussian filter.
	*/


	/**
	* Create the Weiner deconvolution filter.
	*/


	/**
	* Create the Weiner deconvolution filter.
	*/


	/**
	* Compute mapping E(u|v)
	*/


	/**
	* Remove the zero-padding from the mapping
	*/

	/**
	* Sharpen the image with the new mapping, E(u|v)
	*/
}


void UpdateBiasFieldEstimate()
{
	/**
	* Calculate min/max for sigmoid weighting.  Calculate mean for offseting
	* bias field calculations since B-spline algorithm biases the result
	* to zero.
	*/


	/**
	* Get original direction and change to identity temporarily for the
	* b-spline fitting.
	*/


	/**
	* Add the bias field control points to the current estimate.
	*/

}


void CalculateConvergenceMeasurement()
{
	/**
	* Calculate statistics over the mask region
	*/


}