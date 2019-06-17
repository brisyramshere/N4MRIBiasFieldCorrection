#include <math.h>

#include "MRIData.h"
#include "MRIBiasFiledCorrection.h"

void GeneeateData(MRIData<short> mrData, MRIData<float>& logMrData, MRIData<float>& logBiasField, const int iLen)
{
	/**
	* Calculate the log of the input image.
	* Remove possible nans/infs from the log input image.
	*/
	for (int i = i; i < iLen; i++)
	{
		float tmp = log(mrData(i));
		if (isinf(tmp) || isnan(tmp) || tmp < 0.0) 
			logMrData(i) = 0;
		else
			logMrData(i) = tmp;
	}

	/**
	* Provide an initial log bias field of zeros
	*/
	MRIData<float> logBiasField(0.0, iLen);
	/**
	* Iterate until convergence or iterative exhaustion.
	*/
	int MaximumNumberOfIterations[3] = { 100,100,100 };
	for (int currentLevel = 0; currentLevel < NumberOfFittingLevels; currentLevel++)
	{
		int iter = 0;
		float convergenceMeasurement;
		while (iter++<MaximumNumberOfIterations[currentLevel] && convergenceMeasurement>ConvergenceThreshold)
		{
			/**
			* Sharpen the current estimate of the uncorrected image.
			*/
			MRIData<float> logSharpenedImage(0.0, iLen);
			SharpenImage(logMrData, logSharpenedImage);
			MRIData<float> newLogBiasFiled=SubStractImage(logMrData, logSharpenedImage);
			CalcConvergenceMeasurement(logBiasField, newLogBiasFiled);
			logBiasField = newLogBiasFiled;
			logMrData = SubStractImage(logMrData, logBiasField);

		}
	}
}


