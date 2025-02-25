.. index:: fix rheo/pressure

fix rheo/pressure command
=========================

Syntax
""""""

.. parsed-literal::

   fix ID group-ID rheo/pressure type1 pstyle1 args1 ... typeN pstyleN argsN

* ID, group-ID are documented in :doc:`fix <fix>` command
* rheo/pressure = style name of this fix command
* one or more types and pressure styles must be appended
* types = lists of types (see below)
* pstyle = *linear* or *tait/water* or *tait/general* or *cubic* or *ideal/gas* or *background*

  .. parsed-literal::

       *linear* args = none
       *tait/water* args = none
       *tait/general* args = exponent :math:`gamma` (unitless)
       *cubic* args = cubic prefactor :math:`A_3` (pressure/density\^2)
       *ideal/gas* args = heat capacity ratio :math:`gamma` (unitless)
       *background* args = background pressure :math:`P[b]` (pressure)

Examples
""""""""

.. code-block:: LAMMPS

   fix 1 all rheo/pressure * linear
   fix 1 all rheo/pressure 1 linear 2 cubic 10.0
   fix 1 all rheo/pressure * linear * background 0.1

Description
"""""""""""

.. versionadded:: 29Aug2024

This fix defines a pressure equation of state for RHEO particles. One can
define different equations of state for different atom types. An equation
must be specified for every atom type.

One first defines the atom *types*. A wild-card asterisk can be used in place
of or in conjunction with the *types* argument to set values for multiple atom
types.  This takes the form "\*" or "\*n" or "m\*" or "m\*n".  If :math:`N` is
the number of atom types, then an asterisk with no numeric values means all types
from 1 to :math:`N`.  A leading asterisk means all types from 1 to n (inclusive).
A trailing asterisk means all types from m to :math:`N` (inclusive).  A middle
asterisk means all types from m to n (inclusive).

The *types* definition is followed by the pressure style, *pstyle*. Current
options *linear*, *taitwater*, and *cubic*. Style *linear* is a linear
equation of state with a particle pressure :math:`P` calculated as

.. math::

   P = c^2 (\rho - \rho_0)

where :math:`c` is the speed of sound, :math:`\rho_0` is the equilibrium density,
and :math:`\rho` is the current density of a particle. The numerical values of
:math:`c` and :math:`\rho_0` are set in :doc:`fix rheo <fix_rheo>`. Style *cubic*
is a cubic equation of state which has an extra argument :math:`A_3`,

.. math::

   P = c^2 ((\rho - \rho_0) + A_3 (\rho - \rho_0)^3) .

Style *tait/water* is Tait's equation of state:

.. math::

   P = \frac{c^2 \rho_0}{7} \biggl[\left(\frac{\rho}{\rho_0}\right)^{7} - 1\biggr].

Style *tait/general* generalizes this equation of state

.. math::

   P = \frac{c^2 \rho_0}{\gamma} \biggl[\left(\frac{\rho}{\rho_0}\right)^{\gamma} - 1\biggr].

where :math:`\gamma` is an exponent.

Style *ideal/gas* is the ideal gas equation of state

.. math::

   P = (\gamma - 1) \rho e

where :math:`\gamma` is the heat capacity ratio and :math:`e` is the internal energy of
a particle per unit mass. This style is only compatible with atom style rheo/thermal.
Note that when using this style, the speed of sound is no longer constant such that the
value of :math:`c` specified in :doc:`fix rheo <fix_rheo>` is not used.

The *background* style acts differently than the rest as it
only adds a constant background pressure shift :math:`P[b]`
to all atoms of the designated types. Therefore, this style
must be used in conjunction with another style that specifies
an equation of state.

Restart, fix_modify, output, run start/stop, minimize info
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

No information about this fix is written to :doc:`binary restart files <restart>`.
None of the :doc:`fix_modify <fix_modify>` options
are relevant to this fix.  No global or per-atom quantities are stored
by this fix for access by various :doc:`output commands <Howto_output>`.
No parameter of this fix can be used with the *start/stop* keywords of
the :doc:`run <run>` command.  This fix is not invoked during :doc:`energy minimization <minimize>`.

Restrictions
""""""""""""

This fix must be used with an atom style that includes density
such as atom_style rheo or rheo/thermal. This fix must be used in
conjunction with :doc:`fix rheo <fix_rheo>`. The fix group must be
set to all. Only one instance of fix rheo/pressure can be defined.

This fix is part of the RHEO package.  It is only enabled if
LAMMPS was built with that package.  See the :doc:`Build package <Build_package>`
page for more info.

Related commands
""""""""""""""""

:doc:`fix rheo <fix_rheo>`,
:doc:`pair rheo <pair_rheo>`,
:doc:`compute rheo/property/atom <compute_rheo_property_atom>`

Default
"""""""

none
