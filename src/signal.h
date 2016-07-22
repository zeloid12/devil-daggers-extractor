#ifndef SIGNAL_H
#define SIGNAL_H

#include <vector>

template <typename t_return, typename... t_args>
class Signal
{
private:

    using signature = std::function<t_return(t_args...)>;

    struct Slot
    {
        uint32_t m_id;
        signature m_callback;
    };

public:

    uint32_t connect(signature callback)
    {
        uint32_t id = 0;
        {
            if (!m_slots.empty())
            {
                id = m_slots.back().m_id + 1;
            }
            m_slots.push_back({ id, callback });
        }

        return id;
    }

    void disconnect(uint32_t id)
    {
        auto it = m_slots.begin();
        while (it != m_slots.end())
        {
            if (it->m_id == id)
            {
                m_slots.erase(id);
                return;
            }

            ++it;
        }
    }

    void fire(t_args&&... arguments)
    {
        for (auto& slot : m_slots)
        {
            slot.m_callback(std::forward<t_args>(arguments)...);
        }
    }

private:

    std::vector<Slot> m_slots;
};

#endif // SIGNAL_H
