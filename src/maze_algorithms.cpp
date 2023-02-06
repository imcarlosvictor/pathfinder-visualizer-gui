#include "../include/maze_algorithms.h"

void MazeAlgorithms::RecursiveDivision(Grid* grid_ptr) {
    std::cout << "recursive div" << std::endl;    
    std::cout << grid_ptr->getGridDimension().rows << std::endl;    
    std::cout << grid_ptr->getGridDimension().columns << std::endl;    
    
    // TODO: Implement recursive maze algorithm
    /* IF the grid has a dimension of 1x1 */
    /*     RETURN */
    /* ELSE */
    /*     SET random_num as a random number from 0 to (width + height) */
    /*     SET wall_indices as the index of all floor tiles that will be converted to walls */

    /*     // Choose orientation */
    /*     IF random_num is less than width */
    /*         DIVIDE vertically */
    /*     ELSE */
    /*         DIVIDE horizontally */
    /*     ENDIF */

    /*     // Create a gap */
    /*     SET gap_index as a random number from 0 to length of array */
    /*     SET the tile in the array with the same index a gap_index to a floor tile */
    /* ENDIF */


    if (true) {
        ;
    } else {
        int random_num = rand() % (grid_ptr->getGridDimension().rows + grid_ptr->getGridDimension().columns);
        
        // Choose orientation
        if (random_num < grid_ptr->getGridDimension().columns)
            Divide(grid_ptr, "vertical");
        else
            Divide(grid_ptr, "horizontal");

        // Create a gap
        std::vector<int> wall_indices; // Stores all indices of the wall
        /* int gap_index = rand() % wall_indices.size(); */ 
    }
}

/* void MazeAlgorithms::Divide(Grid* grid_ptr, std::string orientation) { */
/*     /1* if (orientation == "horizontal") { *1/ */

/*     /1* } else { *1/ */

/*     /1* } *1/ */

/*     std::cout << orientation << std::endl; */
/* } */
