/*
 *@BEGIN LICENSE
 *
 * PSI4: an ab initio quantum chemistry software package
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 *@END LICENSE
 */

/*! \file
    \ingroup DETCAS
    \brief Enter brief description of file here 
*/
/*
** SETUP_IO.C
**
** Contains some setup/shutdown I/O stuff
**
** C. David Sherrill
** University of California, Berkeley
** April 1998
*/

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <libciomr/libciomr.h>
#include <libpsio/psio.h>
#include <libqt/qt.h>
#include "structs.h"
#define EXTERN
#include "globals.h"
#include "psi4-dec.h"

namespace psi { namespace detci {

// /*
// ** init_io(): Function opens input and output files
// */
// void init_io(int argc, char *argv[])
// {
//   int i;
//   int num_extra_args;
//   char **extra_args;
// 
//   extra_args = (char **) malloc(argc*sizeof(char *)); 
//   for (i=1,num_extra_args=0; i<argc; i++) {
//     if (strcmp(argv[i], "--quiet") == 0) {
//       MCSCF_Parameters.print_lvl = 0;
//     }
//     else {
//       extra_args[num_extra_args++] = argv[i];
//     }
//   }
//  
//   psi_start(&infile,&outfile,&psi_file_prefix,num_extra_args, extra_args, 0); 
// 
//   /*
//   init_in_out(argc-parsed,argv+parsed);
//   ip_set_uppercase(1);
//   ip_initialize(infile, outfile);
//   ip_cwk_clear();
//   ip_cwk_add(":DEFAULT");
//   */
// 
//   if (MCSCF_Parameters.print_lvl) tstart(outfile);
//   ip_cwk_add(":DETCAS");
//   psio_init(); psio_ipv1_config();
// 
//   free(extra_args);
// }



// /*
// ** close_io(): Function closes down I/O and exits
// */
// void close_io(void)
// {
//    psio_done();
//    if (MCSCF_Parameters.print_lvl) tstop(outfile);
//    psi_stop(infile,outfile,psi_file_prefix);
// }
// 
// 
// 
/*
** check() acts as an abort function if the condition 'a' is not true;
**   it shuts down i/o and returns an error
*/
void check(int a, const char *errmsg)
{
  if (!a) {
    // outfile->Printf("%s\n", errmsg);
    // close_io();
    std::string err_string(errmsg);
    throw PsiException(err_string, __FILE__, __LINE__);
    //exit(1);
  }
}

}} // end namespace psi::detci


/*
** The gprgid() function required by the PSI I/O libraries
*/
extern "C" {
  const char *gprgid()
  {
    const char *prgid = "DETCAS";
    return(prgid);
  }
}


