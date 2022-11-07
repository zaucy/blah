#include <blah.h>
using namespace Blah;

Batch batch;

int main()
{
    Config config;
    config.name = "blah app";
    config.on_render = []()
    {
        App::backbuffer()->clear(Color::black);

        auto center = App::get_backbuffer_size() / 2;
        auto rotation = Time::seconds * Calc::TAU;
        auto transform = Mat3x2f::create_transform(center, Vec2f::zero, Vec2f::one, rotation);

        batch.push_matrix(transform);
        batch.rect(Rectf(-32, -32, 64, 64), Color::red);
        batch.pop_matrix();

        batch.render();
        batch.clear();
    };

    App::run(&config);
    return 0;
}
