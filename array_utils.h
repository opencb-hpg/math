#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

    public static double log(double value, double base) {
		return Math.log(value)/Math.log(base);
	}
	
	public static double roundDigits(double a,double d)	{
		return (double) Math.round(a*Math.pow(10.0,d))/Math.pow(10.0,d) ;
	}

	public static double[] scalarMultiply(double[] data, double value) {
		double[] newData = new double[data.length];
		for(int i=0; i<data.length; i++) { 
			newData[i] = data[i] * value;
		}
		return newData;
	}

	public static double[] scalarSum(double[] data, double value) {
		double[] newData = new double[data.length];
		for(int i=0; i<data.length; i++) { 
			newData[i] = data[i] + value;
		}
		return newData;
	}

	public static double[] arraySum(double[] data1, double[] data2) {
		if(data1.length != data2.length) {
			return null;
		}
		double[] newData = new double[data1.length];
		for(int i=0; i<data1.length; i++) { 
			newData[i] = data1[i] + data2[i];
		}
		return newData;
	}
	
	public static double[] arraySubstract(double[] data1, double[] data2) {
		if(data1.length != data2.length) {
			return null;
		}
		double[] newData = new double[data1.length];
		for(int i=0; i<data1.length; i++) { 
			newData[i] = data1[i] - data2[i];
		}
		return newData;
	}

	public static double[] log(double[] values) {
		double[] logValues = new double[values.length];
		for(int i=0;i<logValues.length; i++) {
			logValues[i] = Math.log(values[i]);
		}
		return logValues;
	}

	public static double[] log10(double[] values) {
		double[] logValues = new double[values.length];
		for(int i=0;i<logValues.length; i++) {
			logValues[i] = Math.log10(values[i]);
		}
		return logValues;
	}

	public static double[] log(double[] values, double base) {
		double[] logValues = new double[values.length];
		double d;
		for(int i=0;i<logValues.length; i++) {
			d = Math.log(values[i])/Math.log(base);
			if(d == -0.0) {
				d = 0.0;
			}
			logValues[i] = d;
		}
		return logValues;
	}
	public static double sum(final double[] values) {
		return sum(values, 0, values.length);
	}

	public static double sum(final double[] values, int begin, int end) {
		double sum = Double.NaN;
		if (checkArguments(values, begin, end)) {
			sum = 0.0;
			for (int i = begin; i < end; i++) {
				if(!Double.isNaN(values[i])) {
					sum += values[i];				
				}
			}
		}
		return sum;
	}

	
#endif
