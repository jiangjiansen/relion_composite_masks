Please follow the instructions at https://github.com/3dem/relion for compilation and installation.

## How to use composite masks

![Composite masks](images/relion5_composite_masks.png?raw=true)

For membrane proteins, use a soft mask encompassing the whole particle, including both the protein(s) and the detergent/lipid micelle, as the reference mask and a soft mask generated from segmented protein densities as the mask of protein of interest. Set the composite low-pass filter to the desired resolution, such as 20 Å. During 3D classification or 3D auto-refinement, the micelle region (the difference between the reference mask and the mask of protein of interest) is low-pass filtered.

If the mask of protein of interest is omitted or the composite low-pass filter is set to a negative number, the composte mask function is disabled.

If you would like to cite this composite mask method, please cite: Dou, T., Lian, T., Shu, S. et al. The substrate and inhibitor binding mechanism of polyspecific transporter OAT1 revealed by high-resolution cryo-EM. Nat Struct Mol Biol 30, 1794–1805 (2023). https://doi.org/10.1038/s41594-023-01123-3



RELION 5.0.0
============

RELION (for REgularised LIkelihood OptimisatioN) is a stand-alone computer
program for Maximum A Posteriori refinement of (multiple) 3D reconstructions
or 2D class averages in cryo-electron microscopy. It is developed in the
research group of Sjors Scheres at the MRC Laboratory of Molecular Biology.

If RELION is useful in your work, please cite our papers.

Comprehensive documentation of RELION and tutorials are stored [here](https://relion.readthedocs.io/).

## Installation

See our [installation instructions](https://relion.readthedocs.io/en/release-5.0/Installation.html).

You will have to set up a Python environment to use Python modules (e.g. Blush, ModelAngelo and DynaMight).
Thus, please read the above instructions carefully even if you are familiar with earlier versions.

## Class Ranker

The default model for the class ranker has been trained and tested in Python 3.9.12 with Pytorch 1.10.0 and Numpy 1.20.0.
If you wish to retrain the class ranker model with your own data, please refer to [this repo](https://github.com/3dem/relion-classranker).
