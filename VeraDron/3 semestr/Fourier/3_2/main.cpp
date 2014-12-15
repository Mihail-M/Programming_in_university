#include <algorithm>
#include <iostream>
#include <complex>
#include <math.h>
#include <vector>


#include "wav-file.h"
#include "wav-writer.h"

const double pi = 3.14159265358979323846;
const double eps = 0.000001;

using namespace std;

void DFT(int N, int start, short *a, vector <complex<double> > &b) {
    for (int k = 0; k < N; k++)
        for (int n = 0; n < N; n++)
        {
            double f = -2 * pi * k * n / N;
            b[k] += complex<double>((double)a[start + n], 0) * complex<double>(cos(f), sin(f));
        }


}

void RDFT(int N, int start, vector <complex<double> > &b, short *&a) {
    for (int n = 0; n < N; n++)
    {
        complex<double> sum = complex<double>(0);

        for (int k = 0; k < N; k++) {
            double f = 2 * pi * n * k / N;
            sum += b[k] * complex<double>(cos(f), sin(f));
        }
        a[start + n] = real(sum) / N;
    }
}

int main() {
    char* fileName = "example3_noisy.wav";
    WavFile* pObjWavFile;
    std::cout << "FileName is: " << fileName;
    pObjWavFile = new WavFile;
    if (EXIT_SUCCESS != pObjWavFile->openWavFile(fileName))
    {
        std::cout << "\nCan't load wav file.";
        exit(-1);
    }

    pObjWavFile->displayInformation(fileName);

    double sample_rate = pObjWavFile->getSampleRateHz();
    int num_channels = pObjWavFile->getNumChannels();
    int num_samples = pObjWavFile->getNumSamples();
    num_samples /= num_channels;

    short *data = new short[num_samples];

    int count = 0;
    for (; pObjWavFile->ifMoreDataAvailable(); ++count)
    {
        data[count] = 0;
        for (int i = 0; i < num_channels; ++i) {
            data[count] += (short)pObjWavFile->readCurrentInput();
        }
        data[count] /= num_channels;
    }

    double end = count / sample_rate;
    complex<double> theBestMaxAmpl = complex<double>(0);
    int theBestMaxFreq = 0;

    double currentBeg = 0.0;
    double currentEnd = 0.0;

    short * result = new short[num_samples];

    while (currentEnd < end)
    {
        currentEnd = (currentEnd + 0.012 > end ? end : currentEnd + 0.012);

        int N = (currentEnd - currentBeg) * sample_rate;

        vector<complex<double> > ampl(N, complex<double>(0));

        int start = currentBeg * sample_rate;
        DFT(N, start, data, ampl);

        int maxFreq = 0;
        for (int k = 0; k < N; k++)
            if (abs(ampl[k]) >= abs(ampl[maxFreq]))
                maxFreq = k;

        if (abs(theBestMaxAmpl) < abs(ampl[maxFreq]))
        {
            theBestMaxFreq = maxFreq;
            theBestMaxAmpl = ampl[maxFreq];
        }

        for (int i = 0; i < N; i++)
            if (abs(ampl[i]) < abs(ampl[maxFreq]) * 0.25)
                ampl[i] = complex<double>(0.0);

        RDFT(N, start, ampl, result);
        currentBeg = currentEnd;

    }

    cout << "Loudest frequency: " << theBestMaxFreq / 0.012 << " Hz" << endl;

    int endFILE = end * sample_rate;
    double startFILE = 0.0;

    writeWAVData<short>("example3.wav", result,
                        (endFILE - startFILE) * sizeof(short), sample_rate, 1);

    delete [] result;
    delete [] data;
    delete pObjWavFile;
    cout << "DONE!!!";
    return 0;
}
