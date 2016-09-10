using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(Fitrail.Startup))]
namespace Fitrail
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
