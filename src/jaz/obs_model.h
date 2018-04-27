#ifndef OBS_MODEL_H
#define OBS_MODEL_H

#include <src/image.h>
#include <src/fftw.h>
#include <src/complex.h>
#include <src/metadata_table.h>
#include <src/projector.h>

class BackProjector;

class ObservationModel
{
    public:

        ObservationModel();
        ObservationModel(double angpix);
        ObservationModel(double angpix, double Cs, double voltage, double beamtilt_x, double beamtilt_y);

            double angpix, lambda, Cs;
            double beamtilt_x, beamtilt_y;
            double beamtilt_xx, beamtilt_xy, beamtilt_yy;
            bool hasTilt, anisoTilt, ctfTilt;
			
		void predictObservation(
				Projector &proj, const MetaDataTable &mdt, int particle,
				MultidimArray<Complex>& dest,
				bool applyCtf = true, bool applyTilt = true, bool applyShift = true) const;
		
		Image<Complex> predictObservation(
				Projector &proj, const MetaDataTable &mdt, int particle,
				bool applyCtf = true, bool applyTilt = true, bool applyShift = true) const;

        std::vector<Image<Complex>> predictObservations(
                Projector &proj, const MetaDataTable &mdt, int threads,
                bool applyCtf = true, bool applyTilt = true, bool applyShift = true) const;

        void insertObservation(
                const Image<Complex>& img, BackProjector &bproj,
                const MetaDataTable& mdt, int particle,
                bool applyCtf, bool applyTilt,
                double shift_x = 0.0, double shift_y = 0.0);

        void setAnisoTilt(double xx, double xy, double yy);

        double angToPix(double a, int s);
        double pixToAng(double p, int s);
		
		
		static bool containsAllNeededColumns(const MetaDataTable& mdt);

};

#endif
