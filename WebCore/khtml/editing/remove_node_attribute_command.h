/*
 * Copyright (C) 2005 Apple Computer, Inc.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#ifndef __remove_node_attribute_command_h__
#define __remove_node_attribute_command_h__

#include "edit_command.h"

#include "xml/dom_nodeimpl.h"
#include "dom_qname.h"

namespace khtml {

class RemoveNodeAttributeCommand : public EditCommand
{
public:
    RemoveNodeAttributeCommand(DOM::DocumentImpl *, DOM::ElementImpl *, const DOM::QualifiedName& attribute);
    virtual ~RemoveNodeAttributeCommand();

    virtual void doApply();
    virtual void doUnapply();

    DOM::ElementImpl *element() const { return m_element; }
    const DOM::QualifiedName& attribute() const { return m_attribute; }
    
private:
    DOM::ElementImpl *m_element;
    DOM::QualifiedName m_attribute;
    DOM::DOMString m_oldValue;
};

} // namespace khtml

#endif // __remove_node_attribute_command_h__
