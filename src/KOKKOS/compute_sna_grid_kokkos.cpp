// clang-format off
/* ----------------------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   https://www.lammps.org/, Sandia National Laboratories
   LAMMPS development team: developers@lammps.org

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

#include "compute_sna_grid_kokkos.h"
#include "compute_sna_grid_kokkos_impl.h"

namespace LAMMPS_NS {

template class ComputeSNAGridKokkosDevice<LMPDeviceType>;
#ifdef LMP_KOKKOS_GPU
template class ComputeSNAGridKokkosHost<LMPHostType>;
#endif

}
