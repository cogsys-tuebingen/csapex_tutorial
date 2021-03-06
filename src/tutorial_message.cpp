/// HEADER
#include <csapex_tutorial/tutorial_message.h>

/// PROJECT
#include <csapex/utility/assert.h>
#include <csapex/utility/register_msg.h>

CSAPEX_REGISTER_MESSAGE(csapex::connection_types::TutorialMessage)

using namespace csapex;
using namespace connection_types;

TutorialMessage::TutorialMessage()
    : MessageTemplate<bool, TutorialMessage>("/", 0)
{}


/// YAML
namespace YAML {
Node convert<csapex::connection_types::TutorialMessage>::encode(const csapex::connection_types::TutorialMessage& rhs)
{
    Node node = convert<csapex::connection_types::Message>::encode(rhs);
    node["value"] = rhs.value;
    return node;
}

bool convert<csapex::connection_types::TutorialMessage>::decode(const Node& node, csapex::connection_types::TutorialMessage& rhs)
{
    if(!node.IsMap()) {
        return false;
    }
    convert<csapex::connection_types::Message>::decode(node, rhs);
    rhs.value = node["value"].as<bool>();
    return true;
}
}
