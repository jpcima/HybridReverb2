/***************************************************************************
 *   Copyright (C) 2009 by Christian Borss                                 *
 *   christian.borss@rub.de                                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "ConvolverFactory.h"
#include "Partitioner.h"
#include "HybridConvolverSingle.h"
#include "HybridConvolverDual.h"
#include "HybridConvolverTripple.h"
#include <memory>

HybridConvolver *ConvolverFactory::create(
    const ParamPartitionWisdom &wisdom, SampleData *impulses,
    int sflen, int strategy)
{
    std::unique_ptr<HybridConvolver> convolver;

    Partitioner partitioner(wisdom);
    int hlen = impulses->getDataLen();
    partitioner.analyze(hlen, sflen, strategy);
    int mflen = partitioner.getM();
    int lflen = partitioner.getL();
    int type  = partitioner.getType();

    switch (type) {
    case PARTITION_TYPE_TRIPPLE:
        convolver.reset(new HybridConvolverTripple(sflen, mflen, lflen, impulses));
        break;
    case PARTITION_TYPE_DUAL:
        convolver.reset(new HybridConvolverDual(sflen, mflen, impulses));
        break;
    default:
        convolver.reset(new HybridConvolverSingle(sflen, impulses));
    }

    return convolver.release();
}
