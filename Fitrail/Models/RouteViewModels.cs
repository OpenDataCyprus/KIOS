using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

namespace Fitrail.Models
{
    

    public class RouteViewModel
    {
        public enum select
        {
            Basic,
            Intermediate,
            Expert
            
        }
        public select IntensitySelect { get; set; }

    }


}
