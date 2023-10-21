import {configureStore} from '@reduxjs/toolkit'
import laptopSliceReducer from '../features/laptop/laptopSlice'
import mobileSliceReducer from '../features/mobile/mobileSlice'
import usersSliceReducer from '../features/users/usersSlice'


const store = configureStore({
    reducer: {
        laptop: laptopSliceReducer,
        mobile: mobileSliceReducer,
        users:usersSliceReducer
    }
})

export default store